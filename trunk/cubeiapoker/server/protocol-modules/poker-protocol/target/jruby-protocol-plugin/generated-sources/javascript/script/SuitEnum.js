com.cubeia.games.poker.io.protocol.SuitEnum = function() {
};
    com.cubeia.games.poker.io.protocol.SuitEnum.CLUBS = 0;
    com.cubeia.games.poker.io.protocol.SuitEnum.DIAMONDS = 1;
    com.cubeia.games.poker.io.protocol.SuitEnum.HEARTS = 2;
    com.cubeia.games.poker.io.protocol.SuitEnum.SPADES = 3;
    com.cubeia.games.poker.io.protocol.SuitEnum.HIDDEN = 4;

com.cubeia.games.poker.io.protocol.SuitEnum.makeSuitEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.SuitEnum.CLUBS;
        case 1: return com.cubeia.games.poker.io.protocol.SuitEnum.DIAMONDS;
        case 2: return com.cubeia.games.poker.io.protocol.SuitEnum.HEARTS;
        case 3: return com.cubeia.games.poker.io.protocol.SuitEnum.SPADES;
        case 4: return com.cubeia.games.poker.io.protocol.SuitEnum.HIDDEN;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.SuitEnum.toString = function(value) {
    switch(value) {
        case 0: return "CLUBS";
        case 1: return "DIAMONDS";
        case 2: return "HEARTS";
        case 3: return "SPADES";
        case 4: return "HIDDEN";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)
