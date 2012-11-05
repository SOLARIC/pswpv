com.cubeia.games.poker.io.protocol.TournamentOut = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.TournamentOut.CLASSID;
    };

    this.player = {}; // int;
    this.position = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeInt(this.player);
        byteArray.writeInt(this.position);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.player = byteArray.readInt();
        this.position = byteArray.readInt();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.TournamentOut";
        normalizedObject.details = {};
        normalizedObject.details["player"] = this.player;
        normalizedObject.details["position"] = this.position;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.TournamentOut.CLASSID = 20;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

