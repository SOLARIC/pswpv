com.cubeia.games.poker.io.protocol.GameCard = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.GameCard.CLASSID;
    };

    this.cardId = {}; // int;
    this.suit = {};
    this.rank = {};


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.cardId);
        byteArray.writeUnsignedByte(this.suit);
        byteArray.writeUnsignedByte(this.rank);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.cardId = byteArray.readInt();
        this.suit =  com.cubeia.games.poker.io.protocol.SuitEnum.makeSuitEnum(byteArray.readUnsignedByte());
        this.rank =  com.cubeia.games.poker.io.protocol.RankEnum.makeRankEnum(byteArray.readUnsignedByte());
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.GameCard";
        normalizedObject.details = {};
        normalizedObject.details["cardId"] = this.cardId;
        normalizedObject.details["suit"] = com.cubeia.games.poker.io.protocol.SuitEnum.toString(this.suit);
        normalizedObject.details["rank"] = com.cubeia.games.poker.io.protocol.RankEnum.toString(this.rank);
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.GameCard.CLASSID = 4;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

