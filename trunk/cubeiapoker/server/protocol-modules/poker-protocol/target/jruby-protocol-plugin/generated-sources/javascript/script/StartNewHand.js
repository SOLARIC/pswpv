com.cubeia.games.poker.io.protocol.StartNewHand = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.StartNewHand.CLASSID;
    };

    this.dealerSeatId = {}; // int;
    this.handId = {}; // String;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.dealerSeatId);
        byteArray.writeString(this.handId);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.dealerSeatId = byteArray.readInt();
        this.handId = byteArray.readString();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.StartNewHand";
        normalizedObject.details = {};
        normalizedObject.details["dealerSeatId"] = this.dealerSeatId;
        normalizedObject.details["handId"] = this.handId;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.StartNewHand.CLASSID = 10;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

