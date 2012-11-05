com.cubeia.games.poker.io.protocol.PlayerAction = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerAction.CLASSID;
    };

    this.type = {};
    this.minAmount = {}; // int;
    this.maxAmount = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeUnsignedByte(this.type);
        byteArray.writeInt(this.minAmount);
        byteArray.writeInt(this.maxAmount);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.type =  com.cubeia.games.poker.io.protocol.ActionTypeEnum.makeActionTypeEnum(byteArray.readUnsignedByte());
        this.minAmount = byteArray.readInt();
        this.maxAmount = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerAction";
        normalizedObject.details = {};
        normalizedObject.details["type"] = com.cubeia.games.poker.io.protocol.ActionTypeEnum.toString(this.type);
        normalizedObject.details["minAmount"] = this.minAmount;
        normalizedObject.details["maxAmount"] = this.maxAmount;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerAction.CLASSID = 1;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

