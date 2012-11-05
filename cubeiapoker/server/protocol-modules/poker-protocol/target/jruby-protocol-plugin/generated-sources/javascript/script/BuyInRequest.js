com.cubeia.games.poker.io.protocol.BuyInRequest = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.BuyInRequest.CLASSID;
    };

    this.amount = {}; // int;
    this.sitInIfSuccessful = {}; // Boolean;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.amount);
        byteArray.writeBoolean(this.sitInIfSuccessful);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.amount = byteArray.readInt();
        this.sitInIfSuccessful = byteArray.readBoolean();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.BuyInRequest";
        normalizedObject.details = {};
        normalizedObject.details["amount"] = this.amount;
        normalizedObject.details["sitInIfSuccessful"] = this.sitInIfSuccessful;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.BuyInRequest.CLASSID = 24;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

