com.cubeia.games.poker.io.protocol.PlayerPokerStatus = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerPokerStatus.CLASSID;
    };

    this.player = {}; // int;
    this.status = {};
    this.inCurrentHand = {}; // Boolean;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        byteArray.writeUnsignedByte(this.status);
        byteArray.writeBoolean(this.inCurrentHand);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
        this.status =  com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.makePlayerTableStatusEnum(byteArray.readUnsignedByte());
        this.inCurrentHand = byteArray.readBoolean();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerPokerStatus";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["status"] = com.cubeia.games.poker.io.protocol.PlayerTableStatusEnum.toString(this.status);
        normalizedObject.details["inCurrentHand"] = this.inCurrentHand;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerPokerStatus.CLASSID = 31;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

