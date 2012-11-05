com.cubeia.games.poker.io.protocol.DeckInfo = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.DeckInfo.CLASSID;
    };

    this.size = {}; // int;
    this.rankLow = {};


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.size);
        byteArray.writeUnsignedByte(this.rankLow);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.size = byteArray.readInt();
        this.rankLow =  com.cubeia.games.poker.io.protocol.RankEnum.makeRankEnum(byteArray.readUnsignedByte());
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.DeckInfo";
        normalizedObject.details = {};
        normalizedObject.details["size"] = this.size;
        normalizedObject.details["rankLow"] = com.cubeia.games.poker.io.protocol.RankEnum.toString(this.rankLow);
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.DeckInfo.CLASSID = 35;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

