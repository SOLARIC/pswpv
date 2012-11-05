com.cubeia.games.poker.io.protocol.PlayerSitinRequest = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerSitinRequest.CLASSID;
    };

    this.player = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerSitinRequest";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerSitinRequest.CLASSID = 33;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

