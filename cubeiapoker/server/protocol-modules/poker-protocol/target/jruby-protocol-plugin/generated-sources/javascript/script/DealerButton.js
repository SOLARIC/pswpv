com.cubeia.games.poker.io.protocol.DealerButton = function(){
    this.classId = function() {
        return com.cubeia.games.poker.io.protocol.DealerButton.CLASSID;
    };

    this.seat = {}; // int;


    this.save = function() {
        var byteArray = new FIREBASE.ByteArray();
        byteArray.writeByte(this.seat);
        return byteArray;
    };

    this.load = function(byteArray) {
        this.seat = byteArray.readByte();
    };
    

    this.getNormalizedObject = function() {
        var normalizedObject = {};
        var i;
        normalizedObject.summary = "com.cubeia.games.poker.io.protocol.DealerButton";
        normalizedObject.details = {};
        normalizedObject.details["seat"] = this.seat;
        return normalizedObject;
    };

};

// CLASSID definition 
com.cubeia.games.poker.io.protocol.DealerButton.CLASSID = 11;


// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

