com.cubeia.games.poker.io.protocol.RankEnum = function() {
};
    com.cubeia.games.poker.io.protocol.RankEnum.TWO = 0;
    com.cubeia.games.poker.io.protocol.RankEnum.THREE = 1;
    com.cubeia.games.poker.io.protocol.RankEnum.FOUR = 2;
    com.cubeia.games.poker.io.protocol.RankEnum.FIVE = 3;
    com.cubeia.games.poker.io.protocol.RankEnum.SIX = 4;
    com.cubeia.games.poker.io.protocol.RankEnum.SEVEN = 5;
    com.cubeia.games.poker.io.protocol.RankEnum.EIGHT = 6;
    com.cubeia.games.poker.io.protocol.RankEnum.NINE = 7;
    com.cubeia.games.poker.io.protocol.RankEnum.TEN = 8;
    com.cubeia.games.poker.io.protocol.RankEnum.JACK = 9;
    com.cubeia.games.poker.io.protocol.RankEnum.QUEEN = 10;
    com.cubeia.games.poker.io.protocol.RankEnum.KING = 11;
    com.cubeia.games.poker.io.protocol.RankEnum.ACE = 12;
    com.cubeia.games.poker.io.protocol.RankEnum.HIDDEN = 13;

com.cubeia.games.poker.io.protocol.RankEnum.makeRankEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.RankEnum.TWO;
        case 1: return com.cubeia.games.poker.io.protocol.RankEnum.THREE;
        case 2: return com.cubeia.games.poker.io.protocol.RankEnum.FOUR;
        case 3: return com.cubeia.games.poker.io.protocol.RankEnum.FIVE;
        case 4: return com.cubeia.games.poker.io.protocol.RankEnum.SIX;
        case 5: return com.cubeia.games.poker.io.protocol.RankEnum.SEVEN;
        case 6: return com.cubeia.games.poker.io.protocol.RankEnum.EIGHT;
        case 7: return com.cubeia.games.poker.io.protocol.RankEnum.NINE;
        case 8: return com.cubeia.games.poker.io.protocol.RankEnum.TEN;
        case 9: return com.cubeia.games.poker.io.protocol.RankEnum.JACK;
        case 10: return com.cubeia.games.poker.io.protocol.RankEnum.QUEEN;
        case 11: return com.cubeia.games.poker.io.protocol.RankEnum.KING;
        case 12: return com.cubeia.games.poker.io.protocol.RankEnum.ACE;
        case 13: return com.cubeia.games.poker.io.protocol.RankEnum.HIDDEN;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.RankEnum.toString = function(value) {
    switch(value) {
        case 0: return "TWO";
        case 1: return "THREE";
        case 2: return "FOUR";
        case 3: return "FIVE";
        case 4: return "SIX";
        case 5: return "SEVEN";
        case 6: return "EIGHT";
        case 7: return "NINE";
        case 8: return "TEN";
        case 9: return "JACK";
        case 10: return "QUEEN";
        case 11: return "KING";
        case 12: return "ACE";
        case 13: return "HIDDEN";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

