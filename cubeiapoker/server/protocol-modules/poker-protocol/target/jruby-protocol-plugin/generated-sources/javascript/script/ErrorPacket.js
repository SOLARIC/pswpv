com.cubeia.games.poker.io.protocol.ErrorPacket = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.ErrorPacket.CLASSID;
    };

    this.code = {};
    this.referenceId = {}; // String;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeUnsignedByte(this.code);
        byteArray.writeString(this.referenceId);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.code =  com.cubeia.games.poker.io.protocol.ErrorCodeEnum.makeErrorCodeEnum(byteArray.readUnsignedByte());
        this.referenceId = byteArray.readString();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.ErrorPacket";
        normalizedObject.details = {};
        normalizedObject.details["code"] = com.cubeia.games.poker.io.protocol.ErrorCodeEnum.toString(this.code);
        normalizedObject.details["referenceId"] = this.referenceId;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.ErrorPacket.CLASSID = 2;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

