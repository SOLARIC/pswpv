com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum = function() {
};
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.OK = 0;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.PENDING = 1;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.INSUFFICIENT_FUNDS_ERROR = 2;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.PARTNER_ERROR = 3;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.MAX_LIMIT_REACHED = 4;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.AMOUNT_TOO_HIGH = 5;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.UNSPECIFIED_ERROR = 6;
    com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.SESSION_NOT_OPEN = 7;

com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.makeBuyInResultCodeEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.OK;
        case 1: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.PENDING;
        case 2: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.INSUFFICIENT_FUNDS_ERROR;
        case 3: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.PARTNER_ERROR;
        case 4: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.MAX_LIMIT_REACHED;
        case 5: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.AMOUNT_TOO_HIGH;
        case 6: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.UNSPECIFIED_ERROR;
        case 7: return com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.SESSION_NOT_OPEN;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.toString = function(value) {
    switch(value) {
        case 0: return "OK";
        case 1: return "PENDING";
        case 2: return "INSUFFICIENT_FUNDS_ERROR";
        case 3: return "PARTNER_ERROR";
        case 4: return "MAX_LIMIT_REACHED";
        case 5: return "AMOUNT_TOO_HIGH";
        case 6: return "UNSPECIFIED_ERROR";
        case 7: return "SESSION_NOT_OPEN";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

