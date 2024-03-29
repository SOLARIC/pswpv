com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum = function() {
};
    com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.OK = 0;
    com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.MAX_LIMIT_REACHED = 1;
    com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.UNSPECIFIED_ERROR = 2;

com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.makeBuyInInfoResultCodeEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.OK;
        case 1: return com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.MAX_LIMIT_REACHED;
        case 2: return com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.UNSPECIFIED_ERROR;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.toString = function(value) {
    switch(value) {
        case 0: return "OK";
        case 1: return "MAX_LIMIT_REACHED";
        case 2: return "UNSPECIFIED_ERROR";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

