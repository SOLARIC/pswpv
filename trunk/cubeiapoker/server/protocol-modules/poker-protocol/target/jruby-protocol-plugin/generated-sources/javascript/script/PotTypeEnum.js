com.cubeia.games.poker.io.protocol.PotTypeEnum = function() {
};
    com.cubeia.games.poker.io.protocol.PotTypeEnum.MAIN = 0;
    com.cubeia.games.poker.io.protocol.PotTypeEnum.SIDE = 1;

com.cubeia.games.poker.io.protocol.PotTypeEnum.makePotTypeEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.PotTypeEnum.MAIN;
        case 1: return com.cubeia.games.poker.io.protocol.PotTypeEnum.SIDE;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.PotTypeEnum.toString = function(value) {
    switch(value) {
        case 0: return "MAIN";
        case 1: return "SIDE";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

