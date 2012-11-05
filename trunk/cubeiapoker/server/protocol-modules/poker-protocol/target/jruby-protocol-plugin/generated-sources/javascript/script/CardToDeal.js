com.cubeia.games.poker.io.protocol.CardToDeal = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.CardToDeal.CLASSID;
    };

    this.player = {}; // int;
    this.card = {}; // GameCard;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        byteArray.writeArray(this.card.save());
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
        this.card = new com.cubeia.games.poker.io.protocol.GameCard();
        this.card.load(byteArray);
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.CardToDeal";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["card"] = this.card.getNormalizedObject();
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.CardToDeal.CLASSID = 7;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

