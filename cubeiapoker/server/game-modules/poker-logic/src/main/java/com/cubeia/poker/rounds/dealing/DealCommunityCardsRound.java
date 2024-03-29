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

package com.cubeia.poker.rounds.dealing;

import com.cubeia.poker.action.PokerAction;
import com.cubeia.poker.rounds.Round;
import com.cubeia.poker.rounds.RoundVisitor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * This round has been separated for timing reasons.
 *
 * @author Fredrik Johansson, Cubeia Ltd
 */
public class DealCommunityCardsRound implements Round {

    private static final long serialVersionUID = 1L;

    private static transient Logger log = LoggerFactory.getLogger(DealCommunityCardsRound.class);

    public DealCommunityCardsRound(Dealer dealer) {
        dealer.dealCommunityCards();
    }

    @Override
    public boolean act(PokerAction action) {
        log.info("Perform action not allowed during DealCommunityCardsRound. Action received: " + action);
        return false;
    }

    @Override
    public String getStateDescription() {
        return "DealCommunityCardsRound";
    }

    @Override
    public boolean isFinished() {
        return true;
    }

    @Override
    public void visit(RoundVisitor visitor) {
        visitor.visit(this);
    }

    @Override
    public void timeout() {
        //nothing
    }

    @Override
    public boolean isWaitingForPlayer(int playerId) {
        return false;
    }

}
