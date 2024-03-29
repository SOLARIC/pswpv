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

package com.cubeia.poker.rounds.betting;

import com.cubeia.poker.adapter.ServerAdapterHolder;
import com.cubeia.poker.variant.GameType;
import com.cubeia.poker.context.PokerContext;
import com.cubeia.poker.PokerState;
import com.cubeia.poker.adapter.ServerAdapter;
import com.cubeia.poker.player.PokerPlayer;
import com.cubeia.poker.timing.impl.DefaultTimingProfile;
import com.cubeia.poker.variant.texasholdem.TexasHoldemFutureActionsCalculator;
import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;

import java.util.SortedMap;
import java.util.TreeMap;

import static org.hamcrest.CoreMatchers.is;
import static org.junit.Assert.assertThat;
import static org.mockito.Mockito.when;
import static org.mockito.MockitoAnnotations.initMocks;

public class BettingRoundAllOtherPlayersAllInTest {

    @Mock
    private GameType telesina;
    @Mock
    private PokerState state;
    @Mock
    private PlayerToActCalculator playerToActCalculator;
    @Mock
    private PokerPlayer player1;
    @Mock
    private PokerPlayer player2;
    @Mock
    private PokerPlayer player3;
    @Mock
    private PokerContext context;
    @Mock
    private ServerAdapterHolder serverAdapterHolder;
    @Mock
    private ServerAdapter serverAdapter;

    private BettingRound round;

    @Before
    public void setUp() throws Exception {
        initMocks(this);

        SortedMap<Integer, PokerPlayer> seatingMap = new TreeMap<Integer, PokerPlayer>();
        seatingMap.put(0, player1);
        seatingMap.put(1, player2);
        seatingMap.put(2, player3);
        when(serverAdapterHolder.get()).thenReturn(serverAdapter);
        when(context.getTimingProfile()).thenReturn(new DefaultTimingProfile());
        when(context.getCurrentHandSeatingMap()).thenReturn(seatingMap);

        ActionRequestFactory actionRequestFactory = new ActionRequestFactory(new NoLimitBetStrategy());
        TexasHoldemFutureActionsCalculator futureActionsCalculator = new TexasHoldemFutureActionsCalculator();
        round = new BettingRound(0, context, serverAdapterHolder, playerToActCalculator, actionRequestFactory, futureActionsCalculator, 0);
    }

    @Test
    public void noPlayerAllIn() {
        when(player1.isAllIn()).thenReturn(false);
        when(player2.isAllIn()).thenReturn(false);
        when(player3.isAllIn()).thenReturn(false);
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player1), is(false));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player2), is(false));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player3), is(false));
    }

    @Test
    public void somePlayersAllIn() {
        when(player1.isAllIn()).thenReturn(true);
        when(player2.isAllIn()).thenReturn(true);
        when(player3.isAllIn()).thenReturn(false);
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player1), is(false));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player2), is(false));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player3), is(true));
    }

    @Test
    public void allPlayersAllIn() {
        when(player1.isAllIn()).thenReturn(true);
        when(player2.isAllIn()).thenReturn(true);
        when(player3.isAllIn()).thenReturn(true);
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player1), is(true));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player2), is(true));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player3), is(true));
    }

    @Test
    public void headsUpWhenOtherIsSitOutAndNotAllIn() {
        SortedMap<Integer, PokerPlayer> seatingMap = new TreeMap<Integer, PokerPlayer>();
        seatingMap.put(0, player1);
        seatingMap.put(1, player2);
        when(state.getCurrentHandSeatingMap()).thenReturn(seatingMap);

        when(player1.isAllIn()).thenReturn(false);
        when(player2.isAllIn()).thenReturn(false);
        when(player2.isSittingOut()).thenReturn(true);

        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player1), is(false));
        assertThat(round.allOtherNonFoldedPlayersAreAllIn(player2), is(false));
    }

}
