#ifndef U_AUTO_PROTOCOL_HPP
#define U_AUTO_PROTOCOL_HPP

#include <string>
#include <vector>

#include "styx.hpp"
#include "styx_istream.hpp"
#include "styx_ostream.hpp"

#ifdef REGISTERED
	#undef REGISTERED
#endif

namespace proto {

const uint32_t version = 1;

namespace suit {
	enum enumeration { CLUBS, DIAMONDS, HEARTS, SPADES, HIDDEN };
}
namespace rank {
	enum enumeration { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, HIDDEN };
}
namespace hand_type {
	enum enumeration { UNKNOWN, HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_STRAIGHT_FLUSH };
}
namespace hand_phase_holdem {
	enum enumeration { PREFLOP, FLOP, TURN, RIVER };
}
namespace hand_phase_5card {
	enum enumeration { BETTING, THIRD_STREET, FOURTH_STREET, FIFTH_STREET };
}
namespace action_type {
	enum enumeration { SMALL_BLIND, BIG_BLIND, CALL, CHECK, BET, RAISE, FOLD, DECLINE_ENTRY_BET, ANTE, BIG_BLIND_PLUS_DEAD_SMALL_BLIND, DEAD_SMALL_BLIND };
}
namespace pot_type {
	enum enumeration { MAIN, SIDE };
}
namespace player_table_status {
	enum enumeration { SITIN, SITOUT };
}
namespace buy_in_result_code {
	enum enumeration { OK, PENDING, INSUFFICIENT_FUNDS_ERROR, PARTNER_ERROR, MAX_LIMIT_REACHED, AMOUNT_TOO_HIGH, UNSPECIFIED_ERROR, SESSION_NOT_OPEN };
}
namespace buy_in_info_result_code {
	enum enumeration { OK, MAX_LIMIT_REACHED, UNSPECIFIED_ERROR };
}
namespace error_code {
	enum enumeration { UNSPECIFIED_ERROR, TABLE_CLOSING, TABLE_CLOSING_FORCED, CLOSED_SESSION_DUE_TO_FATAL_ERROR };
}

struct player_action
{
    enum { class_id = 1 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_action & o)
    {
        ps << static_cast<uint8_t>(o.type);
        ps << o.min_amount;
        ps << o.max_amount;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_action & o)
    {
        uint8_t loadVar;
        ps >> loadVar;
        o.type = static_cast<action_type::enumeration>(loadVar);
        ps >> o.min_amount;
        ps >> o.max_amount;
        return ps;
    }

    action_type::enumeration type;
    int32_t min_amount;
    int32_t max_amount;
};

struct error_packet
{
    enum { class_id = 2 };

    friend styx_ostream & operator<<(styx_ostream & ps, const error_packet & o)
    {
        ps << static_cast<uint8_t>(o.code);
        ps << o.reference_id;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, error_packet & o)
    {
        uint8_t loadVar;
        ps >> loadVar;
        o.code = static_cast<error_code::enumeration>(loadVar);
        ps >> o.reference_id;
        return ps;
    }

    error_code::enumeration code;
    std::string reference_id;
};

struct future_player_action
{
    enum { class_id = 3 };

    friend styx_ostream & operator<<(styx_ostream & ps, const future_player_action & o)
    {
        ps << static_cast<uint8_t>(o.action);
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, future_player_action & o)
    {
        uint8_t loadVar;
        ps >> loadVar;
        o.action = static_cast<action_type::enumeration>(loadVar);
        return ps;
    }

    action_type::enumeration action;
};

struct game_card
{
    enum { class_id = 4 };

    friend styx_ostream & operator<<(styx_ostream & ps, const game_card & o)
    {
        ps << o.card_id;
        ps << static_cast<uint8_t>(o.suit);
        ps << static_cast<uint8_t>(o.rank);
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, game_card & o)
    {
        ps >> o.card_id;
        uint8_t loadVar;
        ps >> loadVar;
        o.suit = static_cast<suit::enumeration>(loadVar);
        uint8_t loadVar;
        ps >> loadVar;
        o.rank = static_cast<rank::enumeration>(loadVar);
        return ps;
    }

    int32_t card_id;
    suit::enumeration suit;
    rank::enumeration rank;
};

struct best_hand
{
    enum { class_id = 5 };

    friend styx_ostream & operator<<(styx_ostream & ps, const best_hand & o)
    {
        ps << o.player;
        ps << static_cast<uint8_t>(o.hand_type);
        ps << o.cards;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, best_hand & o)
    {
        ps >> o.player;
        uint8_t loadVar;
        ps >> loadVar;
        o.hand_type = static_cast<hand_type::enumeration>(loadVar);
        ps >> o.cards;
        return ps;
    }

    int32_t player;
    hand_type::enumeration hand_type;
    std::vector<game_card> cards;
};

struct player_state
{
    enum { class_id = 6 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_state & o)
    {
        ps << o.player;
        ps << o.cards;
        ps << o.balance;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_state & o)
    {
        ps >> o.player;
        ps >> o.cards;
        ps >> o.balance;
        return ps;
    }

    int32_t player;
    std::vector<game_card> cards;
    int32_t balance;
};

struct card_to_deal
{
    enum { class_id = 7 };

    friend styx_ostream & operator<<(styx_ostream & ps, const card_to_deal & o)
    {
        ps << o.player;
        ps << o.card;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, card_to_deal & o)
    {
        ps >> o.player;
        ps >> o.card;
        return ps;
    }

    int32_t player;
    game_card card;
};

struct request_action
{
    enum { class_id = 8 };

    friend styx_ostream & operator<<(styx_ostream & ps, const request_action & o)
    {
        ps << o.current_pot_size;
        ps << o.seq;
        ps << o.player;
        ps << o.allowed_actions;
        ps << o.time_to_act;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, request_action & o)
    {
        ps >> o.current_pot_size;
        ps >> o.seq;
        ps >> o.player;
        ps >> o.allowed_actions;
        ps >> o.time_to_act;
        return ps;
    }

    int32_t current_pot_size;
    int32_t seq;
    int32_t player;
    std::vector<player_action> allowed_actions;
    int32_t time_to_act;
};

struct inform_future_allowed_actions
{
    enum { class_id = 9 };

    friend styx_ostream & operator<<(styx_ostream & ps, const inform_future_allowed_actions & o)
    {
        ps << o.actions;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, inform_future_allowed_actions & o)
    {
        ps >> o.actions;
        return ps;
    }

    std::vector<future_player_action> actions;
};

struct start_new_hand
{
    enum { class_id = 10 };

    friend styx_ostream & operator<<(styx_ostream & ps, const start_new_hand & o)
    {
        ps << o.dealerSeatId;
        ps << o.handId;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, start_new_hand & o)
    {
        ps >> o.dealerSeatId;
        ps >> o.handId;
        return ps;
    }

    int32_t dealerSeatId;
    std::string handId;
};

struct dealer_button
{
    enum { class_id = 11 };

    friend styx_ostream & operator<<(styx_ostream & ps, const dealer_button & o)
    {
        ps << o.seat;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, dealer_button & o)
    {
        ps >> o.seat;
        return ps;
    }

    int8_t seat;
};

struct deal_public_cards
{
    enum { class_id = 12 };

    friend styx_ostream & operator<<(styx_ostream & ps, const deal_public_cards & o)
    {
        ps << o.cards;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, deal_public_cards & o)
    {
        ps >> o.cards;
        return ps;
    }

    std::vector<game_card> cards;
};

struct deal_private_cards
{
    enum { class_id = 13 };

    friend styx_ostream & operator<<(styx_ostream & ps, const deal_private_cards & o)
    {
        ps << o.cards;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, deal_private_cards & o)
    {
        ps >> o.cards;
        return ps;
    }

    std::vector<card_to_deal> cards;
};

struct expose_private_cards
{
    enum { class_id = 14 };

    friend styx_ostream & operator<<(styx_ostream & ps, const expose_private_cards & o)
    {
        ps << o.cards;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, expose_private_cards & o)
    {
        ps >> o.cards;
        return ps;
    }

    std::vector<card_to_deal> cards;
};

struct hand_end
{
    enum { class_id = 15 };

    friend styx_ostream & operator<<(styx_ostream & ps, const hand_end & o)
    {
        ps << o.player_id_reveal_order;
        ps << o.hands;
        ps << o.pot_transfers;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, hand_end & o)
    {
        ps >> o.player_id_reveal_order;
        ps >> o.hands;
        ps >> o.pot_transfers;
        return ps;
    }

    std::vector<int32_t> player_id_reveal_order;
    std::vector<best_hand> hands;
    pot_transfers pot_transfers;
};

struct hand_canceled
{
    enum { class_id = 16 };

    friend styx_ostream & operator<<(styx_ostream & ps, const hand_canceled & o)
    {
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, hand_canceled & o)
    {
        return ps;
    }

};

struct start_hand_history
{
    enum { class_id = 17 };

    friend styx_ostream & operator<<(styx_ostream & ps, const start_hand_history & o)
    {
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, start_hand_history & o)
    {
        return ps;
    }

};

struct stop_hand_history
{
    enum { class_id = 18 };

    friend styx_ostream & operator<<(styx_ostream & ps, const stop_hand_history & o)
    {
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, stop_hand_history & o)
    {
        return ps;
    }

};

struct perform_action
{
    enum { class_id = 19 };

    friend styx_ostream & operator<<(styx_ostream & ps, const perform_action & o)
    {
        ps << o.seq;
        ps << o.player;
        ps << o.action;
        ps << o.bet_amount;
        ps << o.raise_amount;
        ps << o.stack_amount;
        ps << o.timeout;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, perform_action & o)
    {
        ps >> o.seq;
        ps >> o.player;
        ps >> o.action;
        ps >> o.bet_amount;
        ps >> o.raise_amount;
        ps >> o.stack_amount;
        ps >> o.timeout;
        return ps;
    }

    int32_t seq;
    int32_t player;
    player_action action;
    int32_t bet_amount;
    int32_t raise_amount;
    int32_t stack_amount;
    bool timeout;
};

struct tournament_out
{
    enum { class_id = 20 };

    friend styx_ostream & operator<<(styx_ostream & ps, const tournament_out & o)
    {
        ps << o.player;
        ps << o.position;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, tournament_out & o)
    {
        ps >> o.player;
        ps >> o.position;
        return ps;
    }

    int32_t player;
    int32_t position;
};

struct player_balance
{
    enum { class_id = 21 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_balance & o)
    {
        ps << o.balance;
        ps << o.pendingBalance;
        ps << o.player;
        ps << o.players_contribution_to_pot;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_balance & o)
    {
        ps >> o.balance;
        ps >> o.pendingBalance;
        ps >> o.player;
        ps >> o.players_contribution_to_pot;
        return ps;
    }

    int32_t balance;
    int32_t pendingBalance;
    int32_t player;
    int32_t players_contribution_to_pot;
};

struct buy_in_info_request
{
    enum { class_id = 22 };

    friend styx_ostream & operator<<(styx_ostream & ps, const buy_in_info_request & o)
    {
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, buy_in_info_request & o)
    {
        return ps;
    }

};

struct buy_in_info_response
{
    enum { class_id = 23 };

    friend styx_ostream & operator<<(styx_ostream & ps, const buy_in_info_response & o)
    {
        ps << o.max_amount;
        ps << o.min_amount;
        ps << o.balance_in_wallet;
        ps << o.balance_on_table;
        ps << o.mandatory_buyin;
        ps << static_cast<uint8_t>(o.result_code);
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, buy_in_info_response & o)
    {
        ps >> o.max_amount;
        ps >> o.min_amount;
        ps >> o.balance_in_wallet;
        ps >> o.balance_on_table;
        ps >> o.mandatory_buyin;
        uint8_t loadVar;
        ps >> loadVar;
        o.result_code = static_cast<buy_in_info_result_code::enumeration>(loadVar);
        return ps;
    }

    int32_t max_amount;
    int32_t min_amount;
    int32_t balance_in_wallet;
    int32_t balance_on_table;
    bool mandatory_buyin;
    buy_in_info_result_code::enumeration result_code;
};

struct buy_in_request
{
    enum { class_id = 24 };

    friend styx_ostream & operator<<(styx_ostream & ps, const buy_in_request & o)
    {
        ps << o.amount;
        ps << o.sit_in_if_successful;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, buy_in_request & o)
    {
        ps >> o.amount;
        ps >> o.sit_in_if_successful;
        return ps;
    }

    int32_t amount;
    bool sit_in_if_successful;
};

struct buy_in_response
{
    enum { class_id = 25 };

    friend styx_ostream & operator<<(styx_ostream & ps, const buy_in_response & o)
    {
        ps << o.balance;
        ps << o.pending_balance;
        ps << o.amount_brought_in;
        ps << static_cast<uint8_t>(o.result_code);
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, buy_in_response & o)
    {
        ps >> o.balance;
        ps >> o.pending_balance;
        ps >> o.amount_brought_in;
        uint8_t loadVar;
        ps >> loadVar;
        o.result_code = static_cast<buy_in_result_code::enumeration>(loadVar);
        return ps;
    }

    int32_t balance;
    int32_t pending_balance;
    int32_t amount_brought_in;
    buy_in_result_code::enumeration result_code;
};

struct pot
{
    enum { class_id = 26 };

    friend styx_ostream & operator<<(styx_ostream & ps, const pot & o)
    {
        ps << o.id;
        ps << static_cast<uint8_t>(o.type);
        ps << o.amount;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, pot & o)
    {
        ps >> o.id;
        uint8_t loadVar;
        ps >> loadVar;
        o.type = static_cast<pot_type::enumeration>(loadVar);
        ps >> o.amount;
        return ps;
    }

    int8_t id;
    pot_type::enumeration type;
    int32_t amount;
};

struct pot_transfer
{
    enum { class_id = 27 };

    friend styx_ostream & operator<<(styx_ostream & ps, const pot_transfer & o)
    {
        ps << o.pot_id;
        ps << o.player_id;
        ps << o.amount;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, pot_transfer & o)
    {
        ps >> o.pot_id;
        ps >> o.player_id;
        ps >> o.amount;
        return ps;
    }

    int8_t pot_id;
    int32_t player_id;
    int32_t amount;
};

struct pot_transfers
{
    enum { class_id = 28 };

    friend styx_ostream & operator<<(styx_ostream & ps, const pot_transfers & o)
    {
        ps << o.fromPlayerToPot;
        ps << o.transfers;
        ps << o.pots;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, pot_transfers & o)
    {
        ps >> o.fromPlayerToPot;
        ps >> o.transfers;
        ps >> o.pots;
        return ps;
    }

    bool fromPlayerToPot;
    std::vector<pot_transfer> transfers;
    std::vector<pot> pots;
};

struct take_back_uncalled_bet
{
    enum { class_id = 29 };

    friend styx_ostream & operator<<(styx_ostream & ps, const take_back_uncalled_bet & o)
    {
        ps << o.player_id;
        ps << o.amount;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, take_back_uncalled_bet & o)
    {
        ps >> o.player_id;
        ps >> o.amount;
        return ps;
    }

    int32_t player_id;
    int32_t amount;
};

struct rake_info
{
    enum { class_id = 30 };

    friend styx_ostream & operator<<(styx_ostream & ps, const rake_info & o)
    {
        ps << o.total_pot;
        ps << o.total_rake;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, rake_info & o)
    {
        ps >> o.total_pot;
        ps >> o.total_rake;
        return ps;
    }

    int32_t total_pot;
    int32_t total_rake;
};

struct player_poker_status
{
    enum { class_id = 31 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_poker_status & o)
    {
        ps << o.player;
        ps << static_cast<uint8_t>(o.status);
        ps << o.in_current_hand;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_poker_status & o)
    {
        ps >> o.player;
        uint8_t loadVar;
        ps >> loadVar;
        o.status = static_cast<player_table_status::enumeration>(loadVar);
        ps >> o.in_current_hand;
        return ps;
    }

    int32_t player;
    player_table_status::enumeration status;
    bool in_current_hand;
};

struct player_hand_start_status
{
    enum { class_id = 32 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_hand_start_status & o)
    {
        ps << o.player;
        ps << static_cast<uint8_t>(o.status);
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_hand_start_status & o)
    {
        ps >> o.player;
        uint8_t loadVar;
        ps >> loadVar;
        o.status = static_cast<player_table_status::enumeration>(loadVar);
        return ps;
    }

    int32_t player;
    player_table_status::enumeration status;
};

struct player_sitin_request
{
    enum { class_id = 33 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_sitin_request & o)
    {
        ps << o.player;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_sitin_request & o)
    {
        ps >> o.player;
        return ps;
    }

    int32_t player;
};

struct player_sitout_request
{
    enum { class_id = 34 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_sitout_request & o)
    {
        ps << o.player;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_sitout_request & o)
    {
        ps >> o.player;
        return ps;
    }

    int32_t player;
};

struct deck_info
{
    enum { class_id = 35 };

    friend styx_ostream & operator<<(styx_ostream & ps, const deck_info & o)
    {
        ps << o.size;
        ps << static_cast<uint8_t>(o.rank_low);
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, deck_info & o)
    {
        ps >> o.size;
        uint8_t loadVar;
        ps >> loadVar;
        o.rank_low = static_cast<rank::enumeration>(loadVar);
        return ps;
    }

    int32_t size;
    rank::enumeration rank_low;
};

struct external_session_info_packet
{
    enum { class_id = 36 };

    friend styx_ostream & operator<<(styx_ostream & ps, const external_session_info_packet & o)
    {
        ps << o.external_table_reference;
        ps << o.external_table_session_reference;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, external_session_info_packet & o)
    {
        ps >> o.external_table_reference;
        ps >> o.external_table_session_reference;
        return ps;
    }

    std::string external_table_reference;
    std::string external_table_session_reference;
};

struct player_disconnected_packet
{
    enum { class_id = 37 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_disconnected_packet & o)
    {
        ps << o.player_id;
        ps << o.timebank;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_disconnected_packet & o)
    {
        ps >> o.player_id;
        ps >> o.timebank;
        return ps;
    }

    int32_t player_id;
    int32_t timebank;
};

struct player_reconnected_packet
{
    enum { class_id = 38 };

    friend styx_ostream & operator<<(styx_ostream & ps, const player_reconnected_packet & o)
    {
        ps << o.player_id;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, player_reconnected_packet & o)
    {
        ps >> o.player_id;
        return ps;
    }

    int32_t player_id;
};

struct ping_packet
{
    enum { class_id = 39 };

    friend styx_ostream & operator<<(styx_ostream & ps, const ping_packet & o)
    {
        ps << o.identifier;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, ping_packet & o)
    {
        ps >> o.identifier;
        return ps;
    }

    int32_t identifier;
};

struct pong_packet
{
    enum { class_id = 40 };

    friend styx_ostream & operator<<(styx_ostream & ps, const pong_packet & o)
    {
        ps << o.identifier;
        return ps;
    }

    friend styx_istream & operator>>(styx_istream & ps, pong_packet & o)
    {
        ps >> o.identifier;
        return ps;
    }

    int32_t identifier;
};


} // namespace proto

#endif // U_AUTO_PROTOCOL_HPP
