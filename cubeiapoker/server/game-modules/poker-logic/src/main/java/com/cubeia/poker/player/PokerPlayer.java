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

package com.cubeia.poker.player;

import com.cubeia.poker.action.ActionRequest;
import com.cubeia.poker.action.PossibleAction;
import com.cubeia.poker.blinds.BlindsPlayer;
import com.cubeia.poker.blinds.MissedBlindsStatus;
import com.cubeia.poker.hand.Card;
import com.cubeia.poker.hand.Hand;

import java.io.Serializable;
import java.util.Set;

public interface PokerPlayer extends BlindsPlayer, Serializable {

    /**
     * Returns the players pocket cards. Note that this might
     * be a defensive copy and should NOT be modified.
     * Use {@link #addPocketCard(Card, boolean)} to add a card to the player's hand.
     *
     * @return the player's hand, never null.
     */
    public Hand getPocketCards();

    /**
     * Get the players pocket cards that are public (visible to all).
     *
     * @return set of visible pocket cards, never null
     */
    public Set<Card> getPublicPocketCards();

    /**
     * Get the players pocket cards that are private (only visible to player).
     *
     * @return set of visible pocket cards, never null
     */
    public Set<Card> getPrivatePocketCards();

    public void addPocketCard(Card card, boolean publicCard);

    public void clearHand();

    public boolean getSitOutNextRound();

    public void setSitOutNextRound(boolean b);

    /**
     * Gets the player's id.
     *
     * @return
     */
    public int getId();

    public int getSeatId();

    public long getBetStack();

    public void removeFromBetStack(long amount);

    /**
     * Moves the given amount from this player's balance balance to his bet stack
     *
     * @param amount the amount to move
     * @throws IllegalArgumentException if the bet is bigger than the player's stack or if the bet is negative
     */
    public void addBet(long amount);

    /**
     * Adds a bet and goes all-in if the bet is larger than the player's chips stack.
     *
     * @param amount the desired amount
     */
    public void addBetOrGoAllIn(long amount);

    /**
     * Takes chips from the given player, without adding them to his bet stack.
     *
     * @param amount amount the amount to take
     * @throws IllegalArgumentException if the bet is bigger than the player's stack or if the bet is negative
     */
    void takeChips(long amount);

    /**
     * Takes chips from the given player, without adding them to his bet stack and goes all-in if the desired amount is >= the
     * player's current balance.
     *
     * @param amount amount the amount to take
     * @return the amount taken
     */
    long takeChipsOrGoAllIn(long amount);

    public void clearActionRequest();

    public void setActionRequest(ActionRequest possibleActions);

    public ActionRequest getActionRequest();

    public void setHasActed(boolean b);

    public void setHasFolded(boolean b);

    public boolean hasFolded();

    public boolean hasActed();

    public void setHasOption(boolean b);

    public boolean hasOption();

    public void enableOption(PossibleAction option);

    public void setSitOutStatus(SitOutStatus status);

    public SitOutStatus getSitOutStatus();

    public boolean hasPostedEntryBet();

    public void setHasPostedEntryBet(boolean b);

    public boolean isSittingOut();

    public void clearBalance();

    public long getBalance();

    public void setStartingBalance(long startingBalance);

    public long getStartingBalance();


    /**
     * Adds (or removes) chips to the player's chip stack.
     *
     * @param chips chips to add (positive) or remove (negative)
     */
    public void addChips(long chips);

    public boolean isAllIn();

    public void sitIn();

    /**
     * Returns the amount of currency that is not currently available
     * in the current hand but will be added to the {@link #getBalance()} when
     * the hand is finished.
     * This will be nonzero if a player does a buy in during a hand.
     *
     * @return the pending balance
     */
    public long getBalanceNotInHand();

    /**
     * Add the given amount to the balance outside the current hand.
     *
     * @param amount amount to add
     */
    public void addNotInHandAmount(long amount);

    /**
     * move the full amount in betstack to balance
     */
    public void returnBetStackToBalance();

    /**
     * move the amount from betstack to balance
     */
    public void returnBetStackAmountToBalance(long amount);

    /**
     * Adds the balance outside the hand to the ordinary balance.
     *
     * @param maxBuyIn, the total resulting balance should not be higher than this
     * @return returns true if there was an non-zero balance committed
     */
    public boolean commitBalanceNotInHand(long maxBuyIn);

    /**
     * Returns the sum of the balance not in hand and the requested buy ins.
     *
     * @return the sum of requested and balance outside the current hand
     */
    public long getPendingBalanceSum();

    public boolean isSitInAfterSuccessfulBuyIn();

    public void setSitInAfterSuccessfulBuyIn(boolean sitIn);

    /**
     * Get the timestamp for when the player was set as sitting out.
     * Will be null if the player is currently not in a sit out state.
     *
     * @return UTC milliseconds or null
     */
    public Long getSitOutTimestamp();

    public boolean isExposingPocketCards();

    public void setExposingPocketCards(boolean b);

    /**
     * Reset all hand/round specific flags to prepare player for a new hand.
     */
    public void resetBeforeNewHand();

    public void setLastRaiseLevel(long amount);

    public long getLastRaiseLevel();

    /**
     * Returns the amount of requested buy ins for the player.
     *
     * @return amount to buy in
     */
    long getRequestedBuyInAmount();

    /**
     * Add an amount to bring in when hand is finished.
     *
     * @param buyInAmount additional amount
     */
    void addRequestedBuyInAmount(long buyInAmount);

    /**
     * Set an amount to bring in when hand is finished.
     *
     * @param amount the amount
     */
    void setRequestedBuyInAmount(long amount);


    /**
     * Clear the requested future buy in amount and request active flag.
     */
    void clearRequestedBuyInAmountAndRequest();

    /**
     * Mark this player as having a buy in request active. (asynch running against wallet)
     */
    public void buyInRequestActive();

    public boolean isBuyInRequestActive();

    /**
     * @return true if the player has used up his available disconnect extra time
     */
    public boolean isDisconnectTimeoutUsed();

    public void setDisconnectTimeoutUsed(boolean disconnectTimeoutUsed);

    public void setMissedBlindsStatus(MissedBlindsStatus missedBlindsStatus);

    public MissedBlindsStatus getMissedBlindsStatus();
}