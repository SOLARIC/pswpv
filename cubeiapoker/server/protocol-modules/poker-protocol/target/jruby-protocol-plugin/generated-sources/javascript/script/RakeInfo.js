com.cubeia.games.poker.io.protocol.RakeInfo = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.RakeInfo.CLASSID;
    };

    this.totalPot = {}; // int;
    this.totalRake = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.totalPot);
        byteArray.writeInt(this.totalRake);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.totalPot = byteArray.readInt();
        this.totalRake = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.RakeInfo";
        normalizedObject.details = {};
        normalizedObject.details["totalPot"] = this.totalPot;
        normalizedObject.details["totalRake"] = this.totalRake;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.RakeInfo.CLASSID = 30;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

