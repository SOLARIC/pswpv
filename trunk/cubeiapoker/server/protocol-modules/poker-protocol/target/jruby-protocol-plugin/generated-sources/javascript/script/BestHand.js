com.cubeia.games.poker.io.protocol.BestHand = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.BestHand.CLASSID;
    };

    this.player = {}; // int;
    this.handType = {};
    this.cards = [];


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        byteArray.writeUnsignedByte(this.handType);
        byteArray.writeInt(this.cards.length);
        var i;
        for( i = 0; i < this.cards.length; i ++) {
            byteArray.writeArray(this.cards[i].save());
        }
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
        this.handType =  com.cubeia.games.poker.io.protocol.HandTypeEnum.makeHandTypeEnum(byteArray.readUnsignedByte());
        var i;
        var cardsCount = byteArray.readInt();
        var oGameCard;
        this.cards = [];
        for( i = 0; i < cardsCount; i ++) {
            oGameCard = new com.cubeia.games.poker.io.protocol.GameCard();
            oGameCard.load(byteArray);
            this.cards.push(oGameCard);
        }
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.BestHand";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["handType"] = com.cubeia.games.poker.io.protocol.HandTypeEnum.toString(this.handType);
        normalizedObject.details["cards"] = [];
        for ( i = 0; i < this.cards.length; i ++ ) {
            normalizedObject.details["cards"].push(this.cards[i].getNormalizedObject());
        };
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.BestHand.CLASSID = 5;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

