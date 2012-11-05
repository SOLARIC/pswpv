com.cubeia.games.poker.io.protocol.ExposePrivateCards = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.ExposePrivateCards.CLASSID;
    };

    this.cards = [];


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.cards.length);
        var i;
        for( i = 0; i < this.cards.length; i ++) {
            byteArray.writeArray(this.cards[i].save());
        }
        return byteArray;
    };

    this.load = function(byteArray) {
        var i;
        var cardsCount = byteArray.readInt();
        var oCardToDeal;
        this.cards = [];
        for( i = 0; i < cardsCount; i ++) {
            oCardToDeal = new com.cubeia.games.poker.io.protocol.CardToDeal();
            oCardToDeal.load(byteArray);
            this.cards.push(oCardToDeal);
        }
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.ExposePrivateCards";
        normalizedObject.details = {};
        normalizedObject.details["cards"] = [];
        for ( i = 0; i < this.cards.length; i ++ ) {
            normalizedObject.details["cards"].push(this.cards[i].getNormalizedObject());
        };
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.ExposePrivateCards.CLASSID = 14;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

