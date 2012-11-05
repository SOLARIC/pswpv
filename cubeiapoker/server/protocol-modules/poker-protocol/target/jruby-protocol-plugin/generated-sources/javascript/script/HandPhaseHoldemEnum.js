com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum = function() {
};
    com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.PREFLOP = 0;
    com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.FLOP = 1;
    com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.TURN = 2;
    com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.RIVER = 3;

com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.makeHandPhaseHoldemEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.PREFLOP;
        case 1: return com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.FLOP;
        case 2: return com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.TURN;
        case 3: return com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.RIVER;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.HandPhaseHoldemEnum.toString = function(value) {
    switch(value) {
        case 0: return "PREFLOP";
        case 1: return "FLOP";
        case 2: return "TURN";
        case 3: return "RIVER";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

