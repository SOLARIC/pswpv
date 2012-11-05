com.cubeia.games.poker.io.protocol.HandPhase5cardEnum = function() {
};
    com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.BETTING = 0;
    com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.THIRD_STREET = 1;
    com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.FOURTH_STREET = 2;
    com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.FIFTH_STREET = 3;

com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.makeHandPhase5cardEnum = function(value) {
    switch(value) {
        case 0: return com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.BETTING;
        case 1: return com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.THIRD_STREET;
        case 2: return com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.FOURTH_STREET;
        case 3: return com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.FIFTH_STREET;
    }
    return -1;
};

com.cubeia.games.poker.io.protocol.HandPhase5cardEnum.toString = function(value) {
    switch(value) {
        case 0: return "BETTING";
        case 1: return "THIRD_STREET";
        case 2: return "FOURTH_STREET";
        case 3: return "FIFTH_STREET";
    }
    return "INVALID_ENUM_VALUE";
};

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

