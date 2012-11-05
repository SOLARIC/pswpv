com.cubeia.games.poker.io.protocol.TakeBackUncalledBet = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.TakeBackUncalledBet.CLASSID;
    };

    this.playerId = {}; // int;
    this.amount = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.playerId);
        byteArray.writeInt(this.amount);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.playerId = byteArray.readInt();
        this.amount = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.TakeBackUncalledBet";
        normalizedObject.details = {};
        normalizedObject.details["playerId"] = this.playerId;
        normalizedObject.details["amount"] = this.amount;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.TakeBackUncalledBet.CLASSID = 29;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

