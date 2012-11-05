com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum = function() {
};
    com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.SITIN = 0;
    com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.SITOUT = 1;

com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.makePlayerTableStatusEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.SITIN;
        case 1: return com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.SITOUT;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.toString = function(value) {
    switch(value) {
        case 0: return "SITIN";
        case 1: return "SITOUT";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

