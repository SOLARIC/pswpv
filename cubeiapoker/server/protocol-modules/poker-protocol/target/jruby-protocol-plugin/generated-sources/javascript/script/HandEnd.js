com.cubeia.games.poker.io.protocol.HandEnd = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.HandEnd.CLASSID;
    };

    this.playerIdRevealOrder = [];
    this.hands = [];
    this.potTransfers = {}; // PotTransfers;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.playerIdRevealOrder.length);
        var i;
        for( i = 0; i < this.playerIdRevealOrder.length; i ++) {
            byteArray.writeInt(this.playerIdRevealOrder[i]);
        }
        byteArray.writeInt(this.hands.length);
        for( i = 0; i < this.hands.length; i ++) {
            byteArray.writeArray(this.hands[i].save());
        }
        byteArray.writeArray(this.potTransfers.save());
        return byteArray;
    };

    this.load = function(byteArray) {
        var i;
        var playerIdRevealOrderCount = byteArray.readInt();
        this.playerIdRevealOrder = [];
        for (i = 0; i < playerIdRevealOrderCount; i ++) {
            this.playerIdRevealOrder.push(byteArray.readInt());
        }
        var handsCount = byteArray.readInt();
        var oBestHand;
        this.hands = [];
        for( i = 0; i < handsCount; i ++) {
            oBestHand = new com.cubeia.games.poker.io.protocol.BestHand();
            oBestHand.load(byteArray);
            this.hands.push(oBestHand);
        }
        this.potTransfers = new com.cubeia.games.poker.io.protocol.PotTransfers();
        this.potTransfers.load(byteArray);
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.HandEnd";
        normalizedObject.details = {};
        normalizedObject.details["playerIdRevealOrder"] = [];
        for ( i = 0; i < this.playerIdRevealOrder.length; i ++ ) {
            normalizedObject.details["playerIdRevealOrder"].push(this.playerIdRevealOrder[i].getNormalizedObject());
        };
        normalizedObject.details["hands"] = [];
        for ( i = 0; i < this.hands.length; i ++ ) {
            normalizedObject.details["hands"].push(this.hands[i].getNormalizedObject());
        };
        normalizedObject.details["potTransfers"] = this.potTransfers.getNormalizedObject();
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.HandEnd.CLASSID = 15;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

