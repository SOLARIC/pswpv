com.cubeia.games.poker.io.protocol.HandCanceled = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.HandCanceled.CLASSID;
    };



    this.save = function() {
        return [];
    };

    this.load = function(byteArray) {
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.HandCanceled";
        normalizedObject.details = {};
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.HandCanceled.CLASSID = 16;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

