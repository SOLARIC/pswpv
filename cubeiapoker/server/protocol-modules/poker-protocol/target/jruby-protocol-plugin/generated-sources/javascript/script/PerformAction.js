com.cubeia.games.poker.io.protocol.PerformAction = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PerformAction.CLASSID;
    };

    this.seq = {}; // int;
    this.player = {}; // int;
    this.action = {}; // PlayerAction;
    this.betAmount = {}; // int;
    this.raiseAmount = {}; // int;
    this.stackAmount = {}; // int;
    this.timeout = {}; // Boolean;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.seq);
        byteArray.writeInt(this.player);
        byteArray.writeArray(this.action.save());
        byteArray.writeInt(this.betAmount);
        byteArray.writeInt(this.raiseAmount);
        byteArray.writeInt(this.stackAmount);
        byteArray.writeBoolean(this.timeout);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.seq = byteArray.readInt();
        this.player = byteArray.readInt();
        this.action = new com.cubeia.games.poker.io.protocol.PlayerAction();
        this.action.load(byteArray);
        this.betAmount = byteArray.readInt();
        this.raiseAmount = byteArray.readInt();
        this.stackAmount = byteArray.readInt();
        this.timeout = byteArray.readBoolean();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PerformAction";
        normalizedObject.details = {};
        normalizedObject.details["seq"] = this.seq;
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["action"] = this.action.getNormalizedObject();
        normalizedObject.details["betAmount"] = this.betAmount;
        normalizedObject.details["raiseAmount"] = this.raiseAmount;
        normalizedObject.details["stackAmount"] = this.stackAmount;
        normalizedObject.details["timeout"] = this.timeout;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PerformAction.CLASSID = 19;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

