com.cubeia.games.poker.io.protocol.FuturePlayerAction = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.FuturePlayerAction.CLASSID;
    };

    this.action = {};


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeUnsignedByte(this.action);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.action =  com.cubeia.games.poker.io.protocol.ActionTypeEnum.makeActionTypeEnum(byteArray.readUnsignedByte());
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.FuturePlayerAction";
        normalizedObject.details = {};
        normalizedObject.details["action"] = com.cubeia.games.poker.io.protocol.ActionTypeEnum.toString(this.action);
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.FuturePlayerAction.CLASSID = 3;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

