com.cubeia.games.poker.io.protocol.ActionTypeEnum = function() {
};
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.SMALL_BLIND = 0;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.BIG_BLIND = 1;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.CALL = 2;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.CHECK = 3;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.BET = 4;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.RAISE = 5;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.FOLD = 6;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.DECLINE_ENTRY_BET = 7;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.ANTE = 8;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.BIG_BLIND_PLUS_DEAD_SMALL_BLIND = 9;
    com.cubeia.games.poker.io.protocol.ActionTypeEnum.DEAD_SMALL_BLIND = 10;

com.cubeia.games.poker.io.protocol.ActionTypeEnum.makeActionTypeEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.SMALL_BLIND;
        case 1: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.BIG_BLIND;
        case 2: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.CALL;
        case 3: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.CHECK;
        case 4: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.BET;
        case 5: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.RAISE;
        case 6: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.FOLD;
        case 7: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.DECLINE_ENTRY_BET;
        case 8: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.ANTE;
        case 9: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.BIG_BLIND_PLUS_DEAD_SMALL_BLIND;
        case 10: return com.cubeia.games.poker.io.protocol.ActionTypeEnum.DEAD_SMALL_BLIND;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.ActionTypeEnum.toString = function(value) {
    switch(value) {
        case 0: return "SMALL_BLIND";
        case 1: return "BIG_BLIND";
        case 2: return "CALL";
        case 3: return "CHECK";
        case 4: return "BET";
        case 5: return "RAISE";
        case 6: return "FOLD";
        case 7: return "DECLINE_ENTRY_BET";
        case 8: return "ANTE";
        case 9: return "BIG_BLIND_PLUS_DEAD_SMALL_BLIND";
        case 10: return "DEAD_SMALL_BLIND";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

