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

package com.cubeia.poker.variant.texasholdem;

import com.cubeia.poker.action.PokerActionType;
import com.cubeia.poker.player.PokerPlayer;
import com.cubeia.poker.rounds.betting.FutureActionsCalculator;

import java.util.ArrayList;
import java.util.List;

public class TexasHoldemFutureActionsCalculator implements FutureActionsCalculator {


    private static final long serialVersionUID = 6513501780238216186L;

    /* (non-Javadoc)
    * @see com.cubeia.poker.variant.texasholdem.FutureActionsCalculator#calculateFutureActionOptionList(com.cubeia.poker.player.PokerPlayer, java.lang.Long)
    */
    @Override
    public List<PokerActionType> calculateFutureActionOptionList(PokerPlayer player, Long highestBet) {
        List<PokerActionType> options = new ArrayList<PokerActionType>();

        // players that are all in or has folded should not have anything
        if (player.hasFolded() || player.isAllIn() || player.isSittingOut()) {
            return options;
        }

        if (player.getBetStack() >= highestBet) {
            options.add(PokerActionType.CHECK);
        }

        options.add(PokerActionType.FOLD);


        return options;
    }
}
