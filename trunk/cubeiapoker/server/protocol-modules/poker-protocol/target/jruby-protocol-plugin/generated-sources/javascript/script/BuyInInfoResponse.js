com.cubeia.games.poker.io.protocol.BuyInInfoResponse = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.BuyInInfoResponse.CLASSID;
    };

    this.maxAmount = {}; // int;
    this.minAmount = {}; // int;
    this.balanceInWallet = {}; // int;
    this.balanceOnTable = {}; // int;
    this.mandatoryBuyin = {}; // Boolean;
    this.resultCode = {};


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.maxAmount);
        byteArray.writeInt(this.minAmount);
        byteArray.writeInt(this.balanceInWallet);
        byteArray.writeInt(this.balanceOnTable);
        byteArray.writeBoolean(this.mandatoryBuyin);
        byteArray.writeUnsignedByte(this.resultCode);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.maxAmount = byteArray.readInt();
        this.minAmount = byteArray.readInt();
        this.balanceInWallet = byteArray.readInt();
        this.balanceOnTable = byteArray.readInt();
        this.mandatoryBuyin = byteArray.readBoolean();
        this.resultCode =  com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.makeBuyInInfoResultCodeEnum(byteArray.readUnsignedByte());
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.BuyInInfoResponse";
        normalizedObject.details = {};
        normalizedObject.details["maxAmount"] = this.maxAmount;
        normalizedObject.details["minAmount"] = this.minAmount;
        normalizedObject.details["balanceInWallet"] = this.balanceInWallet;
        normalizedObject.details["balanceOnTable"] = this.balanceOnTable;
        normalizedObject.details["mandatoryBuyin"] = this.mandatoryBuyin;
        normalizedObject.details["resultCode"] = com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.toString(this.resultCode);
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.BuyInInfoResponse.CLASSID = 23;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

