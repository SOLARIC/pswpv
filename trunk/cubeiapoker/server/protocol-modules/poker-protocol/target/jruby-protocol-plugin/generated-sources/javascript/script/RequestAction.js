com.cubeia.games.poker.io.protocol.RequestAction = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.RequestAction.CLASSID;
    };

    this.currentPotSize = {}; // int;
    this.seq = {}; // int;
    this.player = {}; // int;
    this.allowedActions = [];
    this.timeToAct = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.currentPotSize);
        byteArray.writeInt(this.seq);
        byteArray.writeInt(this.player);
        byteArray.writeInt(this.allowedActions.length);
        var i;
        for( i = 0; i < this.allowedActions.length; i ++) {
            byteArray.writeArray(this.allowedActions[i].save());
        }
        byteArray.writeInt(this.timeToAct);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.currentPotSize = byteArray.readInt();
        this.seq = byteArray.readInt();
        this.player = byteArray.readInt();
        var i;
        var allowedActionsCount = byteArray.readInt();
        var oPlayerAction;
        this.allowedActions = [];
        for( i = 0; i < allowedActionsCount; i ++) {
            oPlayerAction = new com.cubeia.games.poker.io.protocol.PlayerAction();
            oPlayerAction.load(byteArray);
            this.allowedActions.push(oPlayerAction);
        }
        this.timeToAct = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.RequestAction";
        normalizedObject.details = {};
        normalizedObject.details["currentPotSize"] = this.currentPotSize;
        normalizedObject.details["seq"] = this.seq;
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["allowedActions"] = [];
        for ( i = 0; i < this.allowedActions.length; i ++ ) {
            normalizedObject.details["allowedActions"].push(this.allowedActions[i].getNormalizedObject());
        };
        normalizedObject.details["timeToAct"] = this.timeToAct;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.RequestAction.CLASSID = 8;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

