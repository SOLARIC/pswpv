com.cubeia.games.poker.io.protocol.Pot = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.Pot.CLASSID;
    };

    this.id = {}; // int;
    this.type = {};
    this.amount = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeByte(this.id);
        byteArray.writeUnsignedByte(this.type);
        byteArray.writeInt(this.amount);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.id = byteArray.readByte();
        this.type =  com.cubeia.games.poker.io.protocol.PotTypeEnum.makePotTypeEnum(byteArray.readUnsignedByte());
        this.amount = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.Pot";
        normalizedObject.details = {};
        normalizedObject.details["id"] = this.id;
        normalizedObject.details["type"] = com.cubeia.games.poker.io.protocol.PotTypeEnum.toString(this.type);
        normalizedObject.details["amount"] = this.amount;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.Pot.CLASSID = 26;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

