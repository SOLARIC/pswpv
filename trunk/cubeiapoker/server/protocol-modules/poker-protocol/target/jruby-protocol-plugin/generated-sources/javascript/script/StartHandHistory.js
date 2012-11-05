com.cubeia.games.poker.io.protocol.StartHandHistory = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.StartHandHistory.CLASSID;
    };



    this.save = function() {
        return [];
    };

    this.load = function(byteArray) {
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.StartHandHistory";
        normalizedObject.details = {};
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.StartHandHistory.CLASSID = 17;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

