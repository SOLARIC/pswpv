com.cubeia.games.poker.io.protocol.PingPacket = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PingPacket.CLASSID;
    };

    this.identifier = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.identifier);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.identifier = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PingPacket";
        normalizedObject.details = {};
        normalizedObject.details["identifier"] = this.identifier;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PingPacket.CLASSID = 39;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

