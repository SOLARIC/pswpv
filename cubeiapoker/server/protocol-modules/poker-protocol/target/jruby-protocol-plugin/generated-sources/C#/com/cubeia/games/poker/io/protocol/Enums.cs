// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net;
using Styx;

namespace com.cubeia.games.poker.io.protocol
{

public class Enums {
    private Enums() {}

    public enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES, HIDDEN };

    public static Suit makeSuit(int value) {
        switch(value) {
            case 0: return Suit.CLUBS;
            case 1: return Suit.DIAMONDS;
            case 2: return Suit.HEARTS;
            case 3: return Suit.SPADES;
            case 4: return Suit.HIDDEN;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for Suit: " + value);
        }
    }

    public enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, HIDDEN };

    public static Rank makeRank(int value) {
        switch(value) {
            case 0: return Rank.TWO;
            case 1: return Rank.THREE;
            case 2: return Rank.FOUR;
            case 3: return Rank.FIVE;
            case 4: return Rank.SIX;
            case 5: return Rank.SEVEN;
            case 6: return Rank.EIGHT;
            case 7: return Rank.NINE;
            case 8: return Rank.TEN;
            case 9: return Rank.JACK;
            case 10: return Rank.QUEEN;
            case 11: return Rank.KING;
            case 12: return Rank.ACE;
            case 13: return Rank.HIDDEN;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for Rank: " + value);
        }
    }

    public enum HandType { UNKNOWN, HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_STRAIGHT_FLUSH };

    public static HandType makeHandType(int value) {
        switch(value) {
            case 0: return HandType.UNKNOWN;
            case 1: return HandType.HIGH_CARD;
            case 2: return HandType.PAIR;
            case 3: return HandType.TWO_PAIR;
            case 4: return HandType.THREE_OF_A_KIND;
            case 5: return HandType.STRAIGHT;
            case 6: return HandType.FLUSH;
            case 7: return HandType.FULL_HOUSE;
            case 8: return HandType.FOUR_OF_A_KIND;
            case 9: return HandType.STRAIGHT_FLUSH;
            case 10: return HandType.ROYAL_STRAIGHT_FLUSH;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for HandType: " + value);
        }
    }

    public enum HandPhaseHoldem { PREFLOP, FLOP, TURN, RIVER };

    public static HandPhaseHoldem makeHandPhaseHoldem(int value) {
        switch(value) {
            case 0: return HandPhaseHoldem.PREFLOP;
            case 1: return HandPhaseHoldem.FLOP;
            case 2: return HandPhaseHoldem.TURN;
            case 3: return HandPhaseHoldem.RIVER;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for HandPhaseHoldem: " + value);
        }
    }

    public enum HandPhase5card { BETTING, THIRD_STREET, FOURTH_STREET, FIFTH_STREET };

    public static HandPhase5card makeHandPhase5card(int value) {
        switch(value) {
            case 0: return HandPhase5card.BETTING;
            case 1: return HandPhase5card.THIRD_STREET;
            case 2: return HandPhase5card.FOURTH_STREET;
            case 3: return HandPhase5card.FIFTH_STREET;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for HandPhase5card: " + value);
        }
    }

    public enum ActionType { SMALL_BLIND, BIG_BLIND, CALL, CHECK, BET, RAISE, FOLD, DECLINE_ENTRY_BET, ANTE, BIG_BLIND_PLUS_DEAD_SMALL_BLIND, DEAD_SMALL_BLIND };

    public static ActionType makeActionType(int value) {
        switch(value) {
            case 0: return ActionType.SMALL_BLIND;
            case 1: return ActionType.BIG_BLIND;
            case 2: return ActionType.CALL;
            case 3: return ActionType.CHECK;
            case 4: return ActionType.BET;
            case 5: return ActionType.RAISE;
            case 6: return ActionType.FOLD;
            case 7: return ActionType.DECLINE_ENTRY_BET;
            case 8: return ActionType.ANTE;
            case 9: return ActionType.BIG_BLIND_PLUS_DEAD_SMALL_BLIND;
            case 10: return ActionType.DEAD_SMALL_BLIND;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for ActionType: " + value);
        }
    }

    public enum PotType { MAIN, SIDE };

    public static PotType makePotType(int value) {
        switch(value) {
            case 0: return PotType.MAIN;
            case 1: return PotType.SIDE;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for PotType: " + value);
        }
    }

    public enum PlayerTableStatus { SITIN, SITOUT };

    public static PlayerTableStatus makePlayerTableStatus(int value) {
        switch(value) {
            case 0: return PlayerTableStatus.SITIN;
            case 1: return PlayerTableStatus.SITOUT;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for PlayerTableStatus: " + value);
        }
    }

    public enum BuyInResultCode { OK, PENDING, INSUFFICIENT_FUNDS_ERROR, PARTNER_ERROR, MAX_LIMIT_REACHED, AMOUNT_TOO_HIGH, UNSPECIFIED_ERROR, SESSION_NOT_OPEN };

    public static BuyInResultCode makeBuyInResultCode(int value) {
        switch(value) {
            case 0: return BuyInResultCode.OK;
            case 1: return BuyInResultCode.PENDING;
            case 2: return BuyInResultCode.INSUFFICIENT_FUNDS_ERROR;
            case 3: return BuyInResultCode.PARTNER_ERROR;
            case 4: return BuyInResultCode.MAX_LIMIT_REACHED;
            case 5: return BuyInResultCode.AMOUNT_TOO_HIGH;
            case 6: return BuyInResultCode.UNSPECIFIED_ERROR;
            case 7: return BuyInResultCode.SESSION_NOT_OPEN;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for BuyInResultCode: " + value);
        }
    }

    public enum BuyInInfoResultCode { OK, MAX_LIMIT_REACHED, UNSPECIFIED_ERROR };

    public static BuyInInfoResultCode makeBuyInInfoResultCode(int value) {
        switch(value) {
            case 0: return BuyInInfoResultCode.OK;
            case 1: return BuyInInfoResultCode.MAX_LIMIT_REACHED;
            case 2: return BuyInInfoResultCode.UNSPECIFIED_ERROR;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for BuyInInfoResultCode: " + value);
        }
    }

    public enum ErrorCode { UNSPECIFIED_ERROR, TABLE_CLOSING, TABLE_CLOSING_FORCED, CLOSED_SESSION_DUE_TO_FATAL_ERROR };

    public static ErrorCode makeErrorCode(int value) {
        switch(value) {
            case 0: return ErrorCode.UNSPECIFIED_ERROR;
            case 1: return ErrorCode.TABLE_CLOSING;
            case 2: return ErrorCode.TABLE_CLOSING_FORCED;
            case 3: return ErrorCode.CLOSED_SESSION_DUE_TO_FATAL_ERROR;
            default: throw new ArgumentOutOfRangeException("Invalid enum value for ErrorCode: " + value);
        }
    }

}
}