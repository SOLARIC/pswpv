com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket.CLASSID;
    };

    this.playerId = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.playerId);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.playerId = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket";
        normalizedObject.details = {};
        normalizedObject.details["playerId"] = this.playerId;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket.CLASSID = 38;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

