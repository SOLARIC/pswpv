com.cubeia.games.poker.io.protocol.PlayerHandStartStatus = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerHandStartStatus.CLASSID;
    };

    this.player = {}; // int;
    this.status = {};


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        byteArray.writeUnsignedByte(this.status);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
        this.status =  com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.makePlayerTableStatusEnum(byteArray.readUnsignedByte());
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerHandStartStatus";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["status"] = com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.toString(this.status);
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerHandStartStatus.CLASSID = 32;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

