com.cubeia.games.poker.io.protocol.PlayerState = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.PlayerState.CLASSID;
    };

    this.player = {}; // int;
    this.cards = [];
    this.balance = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        byteArray.writeInt(this.cards.length);
        var i;
        for( i = 0; i < this.cards.length; i ++) {
            byteArray.writeArray(this.cards[i].save());
        }
        byteArray.writeInt(this.balance);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
        var i;
        var cardsCount = byteArray.readInt();
        var oGameCard;
        this.cards = [];
        for( i = 0; i < cardsCount; i ++) {
            oGameCard = new com.cubeia.games.poker.io.protocol.GameCard();
            oGameCard.load(byteArray);
            this.cards.push(oGameCard);
        }
        this.balance = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.PlayerState";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["cards"] = [];
        for ( i = 0; i < this.cards.length; i ++ ) {
            normalizedObject.details["cards"].push(this.cards[i].getNormalizedObject());
        };
        normalizedObject.details["balance"] = this.balance;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.PlayerState.CLASSID = 6;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

