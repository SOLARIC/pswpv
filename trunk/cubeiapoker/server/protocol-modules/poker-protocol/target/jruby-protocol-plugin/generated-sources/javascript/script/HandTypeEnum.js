com.cubeia.games.poker.io.protocol.HandTypeEnum = function() {
};
    com.cubeia.games.poker.io.protocol.HandTypeEnum.UNKNOWN = 0;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.HIGH_CARD = 1;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.PAIR = 2;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.TWO_PAIR = 3;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.THREE_OF_A_KIND = 4;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.STRAIGHT = 5;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.FLUSH = 6;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.FULL_HOUSE = 7;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.FOUR_OF_A_KIND = 8;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.STRAIGHT_FLUSH = 9;
    com.cubeia.games.poker.io.protocol.HandTypeEnum.ROYAL_STRAIGHT_FLUSH = 10;

com.cubeia.games.poker.io.protocol.HandTypeEnum.makeHandTypeEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.HandTypeEnum.UNKNOWN;
        case 1: return com.cubeia.games.poker.io.protocol.HandTypeEnum.HIGH_CARD;
        case 2: return com.cubeia.games.poker.io.protocol.HandTypeEnum.PAIR;
        case 3: return com.cubeia.games.poker.io.protocol.HandTypeEnum.TWO_PAIR;
        case 4: return com.cubeia.games.poker.io.protocol.HandTypeEnum.THREE_OF_A_KIND;
        case 5: return com.cubeia.games.poker.io.protocol.HandTypeEnum.STRAIGHT;
        case 6: return com.cubeia.games.poker.io.protocol.HandTypeEnum.FLUSH;
        case 7: return com.cubeia.games.poker.io.protocol.HandTypeEnum.FULL_HOUSE;
        case 8: return com.cubeia.games.poker.io.protocol.HandTypeEnum.FOUR_OF_A_KIND;
        case 9: return com.cubeia.games.poker.io.protocol.HandTypeEnum.STRAIGHT_FLUSH;
        case 10: return com.cubeia.games.poker.io.protocol.HandTypeEnum.ROYAL_STRAIGHT_FLUSH;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.HandTypeEnum.toString = function(value) {
    switch(value) {
        case 0: return "UNKNOWN";
        case 1: return "HIGH_CARD";
        case 2: return "PAIR";
        case 3: return "TWO_PAIR";
        case 4: return "THREE_OF_A_KIND";
        case 5: return "STRAIGHT";
        case 6: return "FLUSH";
        case 7: return "FULL_HOUSE";
        case 8: return "FOUR_OF_A_KIND";
        case 9: return "STRAIGHT_FLUSH";
        case 10: return "ROYAL_STRAIGHT_FLUSH";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

