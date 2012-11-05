com.cubeia.games.poker.io.protocol.ExternalSessionInfoPacket = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.ExternalSessionInfoPacket.CLASSID;
    };

    this.externalTableReference = {}; // String;
    this.externalTableSessionReference = {}; // String;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeString(this.externalTableReference);
        byteArray.writeString(this.externalTableSessionReference);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.externalTableReference = byteArray.readString();
        this.externalTableSessionReference = byteArray.readString();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.ExternalSessionInfoPacket";
        normalizedObject.details = {};
        normalizedObject.details["externalTableReference"] = this.externalTableReference;
        normalizedObject.details["externalTableSessionReference"] = this.externalTableSessionReference;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.ExternalSessionInfoPacket.CLASSID = 36;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

