com.cubeia.games.poker.io.protocol.PlayerBalance = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerBalance.CLASSID;
    };

    this.balance = {}; // int;
    this.pendingBalance = {}; // int;
    this.player = {}; // int;
    this.playersContributionToPot = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.balance);
        byteArray.writeInt(this.pendingBalance);
        byteArray.writeInt(this.player);
        byteArray.writeInt(this.playersContributionToPot);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.balance = byteArray.readInt();
        this.pendingBalance = byteArray.readInt();
        this.player = byteArray.readInt();
        this.playersContributionToPot = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerBalance";
        normalizedObject.details = {};
        normalizedObject.details["balance"] = this.balance;
        normalizedObject.details["pendingBalance"] = this.pendingBalance;
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["playersContributionToPot"] = this.playersContributionToPot;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerBalance.CLASSID = 21;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

