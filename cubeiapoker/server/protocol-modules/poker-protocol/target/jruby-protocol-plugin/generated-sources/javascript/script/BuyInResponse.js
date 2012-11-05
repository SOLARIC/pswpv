com.cubeia.games.poker.io.protocol.BuyInResponse = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.BuyInResponse.CLASSID;
    };

    this.balance = {}; // int;
    this.pendingBalance = {}; // int;
    this.amountBroughtIn = {}; // int;
    this.resultCode = {};


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.balance);
        byteArray.writeInt(this.pendingBalance);
        byteArray.writeInt(this.amountBroughtIn);
        byteArray.writeUnsignedByte(this.resultCode);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.balance = byteArray.readInt();
        this.pendingBalance = byteArray.readInt();
        this.amountBroughtIn = byteArray.readInt();
        this.resultCode =  com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.makeBuyInResultCodeEnum(byteArray.readUnsignedByte());
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.BuyInResponse";
        normalizedObject.details = {};
        normalizedObject.details["balance"] = this.balance;
        normalizedObject.details["pendingBalance"] = this.pendingBalance;
        normalizedObject.details["amountBroughtIn"] = this.amountBroughtIn;
        normalizedObject.details["resultCode"] = com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.toString(this.resultCode);
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.BuyInResponse.CLASSID = 25;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

