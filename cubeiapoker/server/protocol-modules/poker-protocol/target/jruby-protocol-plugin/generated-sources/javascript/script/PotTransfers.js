com.cubeia.games.poker.io.protocol.PotTransfers = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PotTransfers.CLASSID;
    };

    this.fromPlayerToPot = {}; // Boolean;
    this.transfers = [];
    this.pots = [];


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeBoolean(this.fromPlayerToPot);
        byteArray.writeInt(this.transfers.length);
        var i;
        for( i = 0; i < this.transfers.length; i ++) {
            byteArray.writeArray(this.transfers[i].save());
        }
        byteArray.writeInt(this.pots.length);
        for( i = 0; i < this.pots.length; i ++) {
            byteArray.writeArray(this.pots[i].save());
        }
        return byteArray;
    };

    this.load = function(byteArray) {
        this.fromPlayerToPot = byteArray.readBoolean();
        var i;
        var transfersCount = byteArray.readInt();
        var oPotTransfer;
        this.transfers = [];
        for( i = 0; i < transfersCount; i ++) {
            oPotTransfer = new com.cubeia.games.poker.io.protocol.PotTransfer();
            oPotTransfer.load(byteArray);
            this.transfers.push(oPotTransfer);
        }
        var potsCount = byteArray.readInt();
        var oPot;
        this.pots = [];
        for( i = 0; i < potsCount; i ++) {
            oPot = new com.cubeia.games.poker.io.protocol.Pot();
            oPot.load(byteArray);
            this.pots.push(oPot);
        }
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PotTransfers";
        normalizedObject.details = {};
        normalizedObject.details["fromPlayerToPot"] = this.fromPlayerToPot;
        normalizedObject.details["transfers"] = [];
        for ( i = 0; i < this.transfers.length; i ++ ) {
            normalizedObject.details["transfers"].push(this.transfers[i].getNormalizedObject());
        };
        normalizedObject.details["pots"] = [];
        for ( i = 0; i < this.pots.length; i ++ ) {
            normalizedObject.details["pots"].push(this.pots[i].getNormalizedObject());
        };
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PotTransfers.CLASSID = 28;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

