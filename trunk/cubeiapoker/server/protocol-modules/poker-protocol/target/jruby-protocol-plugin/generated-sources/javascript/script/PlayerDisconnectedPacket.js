com.cubeia.games.poker.io.protocol.PlayerDisconnectedPacket = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerDisconnectedPacket.CLASSID;
    };

    this.playerId = {}; // int;
    this.timebank = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.playerId);
        byteArray.writeInt(this.timebank);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.playerId = byteArray.readInt();
        this.timebank = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerDisconnectedPacket";
        normalizedObject.details = {};
        normalizedObject.details["playerId"] = this.playerId;
        normalizedObject.details["timebank"] = this.timebank;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerDisconnectedPacket.CLASSID = 37;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

