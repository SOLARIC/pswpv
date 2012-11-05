com.cubeia.games.poker.io.protocol.PotTransfer = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PotTransfer.CLASSID;
    };

    this.potId = {}; // int;
    this.playerId = {}; // int;
    this.amount = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeByte(this.potId);
        byteArray.writeInt(this.playerId);
        byteArray.writeInt(this.amount);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.potId = byteArray.readByte();
        this.playerId = byteArray.readInt();
        this.amount = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PotTransfer";
        normalizedObject.details = {};
        normalizedObject.details["potId"] = this.potId;
        normalizedObject.details["playerId"] = this.playerId;
        normalizedObject.details["amount"] = this.amount;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PotTransfer.CLASSID = 27;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

