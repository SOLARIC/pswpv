// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PROTOCOLENUMS_H_15A57C8C_INCLUDE
#define PROTOCOLENUMS_H_15A57C8C_INCLUDE

#ifdef REGISTERED
	#undef REGISTERED
#endif

namespace com_cubeia_games_poker_io_protocol
{
    namespace Suit
    {
        enum Enum { CLUBS, DIAMONDS, HEARTS, SPADES, HIDDEN, ENUM_ERROR = -1 };

        static Enum makeSuit(int value) {
            switch(value) {
                case 0: return CLUBS;
                case 1: return DIAMONDS;
                case 2: return HEARTS;
                case 3: return SPADES;
                case 4: return HIDDEN;

                default: return ENUM_ERROR;
            }
        }

        static Enum SuitError = makeSuit(ENUM_ERROR);

    }
    namespace Rank
    {
        enum Enum { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, HIDDEN, ENUM_ERROR = -1 };

        static Enum makeRank(int value) {
            switch(value) {
                case 0: return TWO;
                case 1: return THREE;
                case 2: return FOUR;
                case 3: return FIVE;
                case 4: return SIX;
                case 5: return SEVEN;
                case 6: return EIGHT;
                case 7: return NINE;
                case 8: return TEN;
                case 9: return JACK;
                case 10: return QUEEN;
                case 11: return KING;
                case 12: return ACE;
                case 13: return HIDDEN;

                default: return ENUM_ERROR;
            }
        }

        static Enum RankError = makeRank(ENUM_ERROR);

    }
    namespace HandType
    {
        enum Enum { UNKNOWN, HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_STRAIGHT_FLUSH, ENUM_ERROR = -1 };

        static Enum makeHandType(int value) {
            switch(value) {
                case 0: return UNKNOWN;
                case 1: return HIGH_CARD;
                case 2: return PAIR;
                case 3: return TWO_PAIR;
                case 4: return THREE_OF_A_KIND;
                case 5: return STRAIGHT;
                case 6: return FLUSH;
                case 7: return FULL_HOUSE;
                case 8: return FOUR_OF_A_KIND;
                case 9: return STRAIGHT_FLUSH;
                case 10: return ROYAL_STRAIGHT_FLUSH;

                default: return ENUM_ERROR;
            }
        }

        static Enum HandTypeError = makeHandType(ENUM_ERROR);

    }
    namespace HandPhaseHoldem
    {
        enum Enum { PREFLOP, FLOP, TURN, RIVER, ENUM_ERROR = -1 };

        static Enum makeHandPhaseHoldem(int value) {
            switch(value) {
                case 0: return PREFLOP;
                case 1: return FLOP;
                case 2: return TURN;
                case 3: return RIVER;

                default: return ENUM_ERROR;
            }
        }

        static Enum HandPhaseHoldemError = makeHandPhaseHoldem(ENUM_ERROR);

    }
    namespace HandPhase5card
    {
        enum Enum { BETTING, THIRD_STREET, FOURTH_STREET, FIFTH_STREET, ENUM_ERROR = -1 };

        static Enum makeHandPhase5card(int value) {
            switch(value) {
                case 0: return BETTING;
                case 1: return THIRD_STREET;
                case 2: return FOURTH_STREET;
                case 3: return FIFTH_STREET;

                default: return ENUM_ERROR;
            }
        }

        static Enum HandPhase5cardError = makeHandPhase5card(ENUM_ERROR);

    }
    namespace ActionType
    {
        enum Enum { SMALL_BLIND, BIG_BLIND, CALL, CHECK, BET, RAISE, FOLD, DECLINE_ENTRY_BET, ANTE, BIG_BLIND_PLUS_DEAD_SMALL_BLIND, DEAD_SMALL_BLIND, ENUM_ERROR = -1 };

        static Enum makeActionType(int value) {
            switch(value) {
                case 0: return SMALL_BLIND;
                case 1: return BIG_BLIND;
                case 2: return CALL;
                case 3: return CHECK;
                case 4: return BET;
                case 5: return RAISE;
                case 6: return FOLD;
                case 7: return DECLINE_ENTRY_BET;
                case 8: return ANTE;
                case 9: return BIG_BLIND_PLUS_DEAD_SMALL_BLIND;
                case 10: return DEAD_SMALL_BLIND;

                default: return ENUM_ERROR;
            }
        }

        static Enum ActionTypeError = makeActionType(ENUM_ERROR);

    }
    namespace PotType
    {
        enum Enum { MAIN, SIDE, ENUM_ERROR = -1 };

        static Enum makePotType(int value) {
            switch(value) {
                case 0: return MAIN;
                case 1: return SIDE;

                default: return ENUM_ERROR;
            }
        }

        static Enum PotTypeError = makePotType(ENUM_ERROR);

    }
    namespace PlayerTableStatus
    {
        enum Enum { SITIN, SITOUT, ENUM_ERROR = -1 };

        static Enum makePlayerTableStatus(int value) {
            switch(value) {
                case 0: return SITIN;
                case 1: return SITOUT;

                default: return ENUM_ERROR;
            }
        }

        static Enum PlayerTableStatusError = makePlayerTableStatus(ENUM_ERROR);

    }
    namespace BuyInResultCode
    {
        enum Enum { OK, PENDING, INSUFFICIENT_FUNDS_ERROR, PARTNER_ERROR, MAX_LIMIT_REACHED, AMOUNT_TOO_HIGH, UNSPECIFIED_ERROR, SESSION_NOT_OPEN, ENUM_ERROR = -1 };

        static Enum makeBuyInResultCode(int value) {
            switch(value) {
                case 0: return OK;
                case 1: return PENDING;
                case 2: return INSUFFICIENT_FUNDS_ERROR;
                case 3: return PARTNER_ERROR;
                case 4: return MAX_LIMIT_REACHED;
                case 5: return AMOUNT_TOO_HIGH;
                case 6: return UNSPECIFIED_ERROR;
                case 7: return SESSION_NOT_OPEN;

                default: return ENUM_ERROR;
            }
        }

        static Enum BuyInResultCodeError = makeBuyInResultCode(ENUM_ERROR);

    }
    namespace BuyInInfoResultCode
    {
        enum Enum { OK, MAX_LIMIT_REACHED, UNSPECIFIED_ERROR, ENUM_ERROR = -1 };

        static Enum makeBuyInInfoResultCode(int value) {
            switch(value) {
                case 0: return OK;
                case 1: return MAX_LIMIT_REACHED;
                case 2: return UNSPECIFIED_ERROR;

                default: return ENUM_ERROR;
            }
        }

        static Enum BuyInInfoResultCodeError = makeBuyInInfoResultCode(ENUM_ERROR);

    }
    namespace ErrorCode
    {
        enum Enum { UNSPECIFIED_ERROR, TABLE_CLOSING, TABLE_CLOSING_FORCED, CLOSED_SESSION_DUE_TO_FATAL_ERROR, ENUM_ERROR = -1 };

        static Enum makeErrorCode(int value) {
            switch(value) {
                case 0: return UNSPECIFIED_ERROR;
                case 1: return TABLE_CLOSING;
                case 2: return TABLE_CLOSING_FORCED;
                case 3: return CLOSED_SESSION_DUE_TO_FATAL_ERROR;

                default: return ENUM_ERROR;
            }
        }

        static Enum ErrorCodeError = makeErrorCode(ENUM_ERROR);

    }
}

#endif
