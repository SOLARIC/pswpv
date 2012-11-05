/**
 * Copyright (C) 2010 Cubeia Ltd <info@cubeia.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

package com.cubeia.backend.firebase;

import com.cubeia.backend.cashgame.AllowJoinResponse;
import com.cubeia.backend.cashgame.LongTransactionId;
import com.cubeia.backend.cashgame.PlayerSessionId;
import com.cubeia.backend.cashgame.PlayerSessionIdImpl;
import com.cubeia.backend.cashgame.TableIdImpl;
import com.cubeia.backend.cashgame.callback.AnnounceTableCallback;
import com.cubeia.backend.cashgame.callback.OpenSessionCallback;
import com.cubeia.backend.cashgame.callback.ReserveCallback;
import com.cubeia.backend.cashgame.dto.*;
import com.cubeia.backend.cashgame.exceptions.BatchHandFailedException;
import com.cubeia.backend.cashgame.exceptions.GetBalanceFailedException;
import com.cubeia.backend.firebase.impl.FirebaseCallbackFactoryImpl;
import com.cubeia.backend.firebase.jmx.MockController;
import com.cubeia.firebase.api.action.service.ServiceAction;
import com.cubeia.firebase.api.server.SystemException;
import com.cubeia.firebase.api.service.RoutableService;
import com.cubeia.firebase.api.service.Service;
import com.cubeia.firebase.api.service.ServiceContext;
import com.cubeia.firebase.api.service.ServiceRouter;
import com.cubeia.games.poker.common.Money;
import com.google.common.collect.LinkedListMultimap;
import com.google.common.collect.Multimap;
import com.google.common.collect.Multimaps;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

public class CashGamesBackendMock implements CashGamesBackendContract, Service, RoutableService {

    private Logger log = LoggerFactory.getLogger(CashGamesBackendMock.class);

    private final AtomicInteger idSequence = new AtomicInteger(0);

    private final Multimap<PlayerSessionId, Money> sessionTransactions =
            Multimaps.<PlayerSessionId, Money>synchronizedListMultimap(LinkedListMultimap.<PlayerSessionId, Money>create());

    private ScheduledExecutorService executor = Executors.newSingleThreadScheduledExecutor();

    private ServiceRouter router;

    @Override
    public String generateHandId() {
        return "" + System.currentTimeMillis();
    }

    @Override
    public boolean isSystemShuttingDown() {
        return false;
    }

    private int nextId() {
        return idSequence.incrementAndGet();
    }

    @Override
    public AllowJoinResponse allowJoinTable(int playerId) {
        return new AllowJoinResponse(true, -1);
    }

    @Override
    public FirebaseCallbackFactory getCallbackFactory() {
        return new FirebaseCallbackFactoryImpl(router);
    }

    @Override
    public void announceTable(AnnounceTableRequest request, final AnnounceTableCallback callback) {
        final AnnounceTableResponse response = new AnnounceTableResponse(new TableIdImpl());
        response.setProperty(MARKET_TABLE_REFERENCE_KEY, "MOCK-TABLE-ID-" + System.currentTimeMillis());

        // Dirty mokkie fix as we cannot run this in the same thread as the participant runs in
        long mockDelay = (long) (Math.random() * 2000);

        executor.schedule(new Runnable() {
            @Override
            public void run() {
                callback.requestSucceeded(response);
            }
        }, mockDelay, TimeUnit.MILLISECONDS);
    }

    /*@Override
    public void closeTable(CloseTableRequest request) {
        log.debug("table removed");
    }*/

    @Override
    public void openSession(OpenSessionRequest request, OpenSessionCallback callback) {
        PlayerSessionId sessionId = new PlayerSessionIdImpl(request.getPlayerId());
        sessionTransactions.put(sessionId, request.getOpeningBalance());

        OpenSessionResponse response = new OpenSessionResponse(sessionId, Collections.<String, String>emptyMap());
        log.debug("new session opened, tId = {}, pId = {}, sId = {}",
                new Object[]{request.getTableId(), request.getPlayerId(), response.getSessionId()});
        log.debug("currently open sessions: {}", sessionTransactions.size());
        callback.requestSucceeded(response);

        printDiagnostics();
    }

    @Override
    public void closeSession(CloseSessionRequest request) {
        PlayerSessionId sid = request.getPlayerSessionId();

        if (!sessionTransactions.containsKey(sid)) {
            log.error("error closing session {}: not found", sid);
        } else {
            Money closingBalance = getBalance(sid);
            sessionTransactions.removeAll(sid);
            log.debug("closed session {} with balance: {}", sid, closingBalance);
        }

        printDiagnostics();
    }

    @Override
    public void reserve(ReserveRequest request, final ReserveCallback callback) {
        Money amount = request.getAmount();
        PlayerSessionId sid = request.getPlayerSessionId();

        if (!sessionTransactions.containsKey(sid)) {
            log.error("reserve failed, session not found: sId = " + sid);
            ReserveFailedResponse failResponse = new ReserveFailedResponse(request.getPlayerSessionId(),
                    ReserveFailedResponse.ErrorCode.SESSION_NOT_OPEN, "session " + sid + " not open", true);
            callback.requestFailed(failResponse);

        } else if (amount.getAmount() == 66 || amount.getAmount() == 660 || amount.getAmount() == 6600) { // MAGIC FAIL FOR 66 cents BUY-IN
            log.error("Failing reserve with {}ms delay for magic amount 66 cents (hardcoded for debug reasons). sId={}", sid);
            final ReserveFailedResponse failResponse = new ReserveFailedResponse(request.getPlayerSessionId(),
                    ReserveFailedResponse.ErrorCode.UNSPECIFIED_FAILURE, "Unknown operator error (magic 66-cent ultra-fail)", true);
            long delay = (long) (Math.random() * 2000);

            executor.schedule(new Runnable() {
                @Override
                public void run() {
                    callback.requestFailed(failResponse);
                }
            }, delay, TimeUnit.MILLISECONDS);

        } else {
            sessionTransactions.put(sid, amount);
            Money newBalance = getBalance(sid);
            BalanceUpdate balanceUpdate = new BalanceUpdate(request.getPlayerSessionId(), newBalance, nextId());
            final ReserveResponse response = new ReserveResponse(balanceUpdate, amount);
            log.debug("reserve successful: sId = {}, amount = {}, new balance = {}", new Object[]{sid, amount, newBalance});
            response.setProperty(MARKET_TABLE_SESSION_REFERENCE_KEY, "MOCK-MARKET-SID-" + sid.hashCode());

            long delay = 0;

            if (amount.getAmount() == 67 || amount.getAmount() == 670 || amount.getAmount() == 6700) {
                delay = (long) (5000 + Math.random() * 10000);
                log.info("succeeding reserve with {}ms delay for magic amount 67 cents (hardcoded for debug reasons). sId={}", delay, sid);
            }

            executor.schedule(new Runnable() {
                @Override
                public void run() {
                    callback.requestSucceeded(response);
                }
            }, delay, TimeUnit.MILLISECONDS);
        }

        printDiagnostics();
    }

    @Override
    public BatchHandResponse batchHand(BatchHandRequest request) throws BatchHandFailedException {
        int totalBets = 0;
        int totalWins = 0;
        int totalRakes = 0;
        List<TransactionUpdate> resultingBalances = new ArrayList<TransactionUpdate>();
        for (HandResult hr : request.getHandResults()) {
            log.debug("recording hand result: handId = {}, sessionId = {}, bets = {}, wins = {}, rake = {}",
                    new Object[]{request.getHandId(), hr.getPlayerSession(), hr.getAggregatedBet(), hr.getWin(), hr.getRake()});
            long amount = hr.getWin().getAmount() - hr.getAggregatedBet().getAmount();
            sessionTransactions.put(hr.getPlayerSession(), new Money(amount, hr.getWin().getCurrencyCode(), hr.getWin().getFractionalDigits()));
            resultingBalances.add(new TransactionUpdate(new LongTransactionId(-1), new BalanceUpdate(hr.getPlayerSession(), getBalance(hr.getPlayerSession()), -1)));

            totalBets += hr.getAggregatedBet().getAmount();
            totalWins += hr.getWin().getAmount();
            totalRakes += hr.getRake().getAmount();
        }

        //Sanity check on the sum
        int sum = totalBets - (totalWins + totalRakes);
        if (sum != 0) {
            throw new BatchHandFailedException("sanity check failed on batchHand, totalBets: " + totalBets + " "
                    + "totalWins: " + totalWins + " totalRakes: " + totalRakes + " sum:" + sum);
        } else {
            log.debug("sanity check successful on batchHand, totalBets: " + totalBets + " "
                    + "totalWins: " + totalWins + " totalRakes: " + totalRakes + " sum:" + sum);
        }

        printDiagnostics();
        return new BatchHandResponse(resultingBalances);
    }

    @Override
    public Money getMainAccountBalance(int playerId) {
        log.debug("getMainAccountBalance is not implemented yet! Returning hardcoded value of 1337000");
        return new Money(90000, "EUR", 2);
    }

    private Money getBalance(PlayerSessionId sid) {
        Money balance = null;

        for (Money tx : sessionTransactions.get(sid)) {
            if (balance == null) {
                balance = tx;
            } else {
                balance = balance.add(tx);
            }
        }
        return balance;
    }

    @Override
    public BalanceUpdate getSessionBalance(PlayerSessionId sessionId)
            throws GetBalanceFailedException {
        printDiagnostics();
        return new BalanceUpdate(sessionId, getBalance(sessionId), nextId());
    }

    private void printDiagnostics() {
//        log.debug("wallet session transactions: ");
//        for (PlayerSessionId session : sessionTransactions.keys()) {
//            log.debug("{} (balance: {}) -> {}", 
//                new Object[] {session, getBalance(session), sessionTransactions.get(session)});
//        }
//        log.debug("---");
    }

    @Override
    public void setRouter(ServiceRouter router) {
        this.router = router;
    }

    public ServiceRouter getRouter() {
        return router;
    }

    @Override
    public void onAction(ServiceAction e) {
        // nothing should arrive here
    }

    @SuppressWarnings("unused")
    @Override
    public void init(ServiceContext con) throws SystemException {
        log.debug("service init");

        log.debug("initializing jmx stuff");
        MockController mockController = new MockController(this);

    }

    @Override
    public void destroy() {
        log.debug("service destroy");
    }

    @Override
    public void start() {
        log.debug("service start");
    }

    @Override
    public void stop() {
        log.debug("service stop");
    }

}
