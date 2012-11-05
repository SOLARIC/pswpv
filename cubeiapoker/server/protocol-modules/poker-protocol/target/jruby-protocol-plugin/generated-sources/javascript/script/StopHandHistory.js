com.cubeia.games.poker.io.protocol.StopHandHistory = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.StopHandHistory.CLASSID;
    };



    this.save = function() {
        return [];
    };

    this.load = function(byteArray) {
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.StopHandHistory";
        normalizedObject.details = {};
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.StopHandHistory.CLASSID = 18;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

