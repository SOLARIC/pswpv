com.cubeia.games.poker.io.protocol.BuyInInfoRequest = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.BuyInInfoRequest.CLASSID;
    };



    this.save = function() {
        return [];
    };

    this.load = function(byteArray) {
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.BuyInInfoRequest";
        normalizedObject.details = {};
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.BuyInInfoRequest.CLASSID = 22;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

