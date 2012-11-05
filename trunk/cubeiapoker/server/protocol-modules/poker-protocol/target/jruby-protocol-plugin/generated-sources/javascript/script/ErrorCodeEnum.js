com.cubeia.games.poker.io.protocol.ErrorCodeEnum = function() {
};
    com.cubeia.games.poker.io.protocol.ErrorCodeEnum.UNSPECIFIED_ERROR = 0;
    com.cubeia.games.poker.io.protocol.ErrorCodeEnum.TABLE_CLOSING = 1;
    com.cubeia.games.poker.io.protocol.ErrorCodeEnum.TABLE_CLOSING_FORCED = 2;
    com.cubeia.games.poker.io.protocol.ErrorCodeEnum.CLOSED_SESSION_DUE_TO_FATAL_ERROR = 3;

com.cubeia.games.poker.io.protocol.ErrorCodeEnum.makeErrorCodeEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.ErrorCodeEnum.UNSPECIFIED_ERROR;
        case 1: return com.cubeia.games.poker.io.protocol.ErrorCodeEnum.TABLE_CLOSING;
        case 2: return com.cubeia.games.poker.io.protocol.ErrorCodeEnum.TABLE_CLOSING_FORCED;
        case 3: return com.cubeia.games.poker.io.protocol.ErrorCodeEnum.CLOSED_SESSION_DUE_TO_FATAL_ERROR;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.ErrorCodeEnum.toString = function(value) {
    switch(value) {
        case 0: return "UNSPECIFIED_ERROR";
        case 1: return "TABLE_CLOSING";
        case 2: return "TABLE_CLOSING_FORCED";
        case 3: return "CLOSED_SESSION_DUE_TO_FATAL_ERROR";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

