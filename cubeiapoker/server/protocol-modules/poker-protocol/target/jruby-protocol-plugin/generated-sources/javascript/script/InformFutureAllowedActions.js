com.cubeia.games.poker.io.protocol.InformFutureAllowedActions = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.InformFutureAllowedActions.CLASSID;
    };

    this.actions = [];


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.actions.length);
        var i;
        for( i = 0; i < this.actions.length; i ++) {
            byteArray.writeArray(this.actions[i].save());
        }
        return byteArray;
    };

    this.load = function(byteArray) {
        var i;
        var actionsCount = byteArray.readInt();
        var oFuturePlayerAction;
        this.actions = [];
        for( i = 0; i < actionsCount; i ++) {
            oFuturePlayerAction = new com.cubeia.games.poker.io.protocol.FuturePlayerAction();
            oFuturePlayerAction.load(byteArray);
            this.actions.push(oFuturePlayerAction);
        }
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.InformFutureAllowedActions";
        normalizedObject.details = {};
        normalizedObject.details["actions"] = [];
        for ( i = 0; i < this.actions.length; i ++ ) {
            normalizedObject.details["actions"].push(this.actions[i].getNormalizedObject());
        };
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.InformFutureAllowedActions.CLASSID = 9;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

