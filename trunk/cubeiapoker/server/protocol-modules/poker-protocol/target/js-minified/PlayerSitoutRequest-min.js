com.cubeia.games.poker.io.protocol.PlayerSitoutRequest=function(){this.classId=function(){return com.cubeia.games.poker.io.protocol.PlayerSitoutRequest.CLASSID};this.player={};this.save=function(){var a=new FIREBASE.ByteArray();a.writeInt(this.player);return a};this.load=function(a){this.player=a.readInt()};this.getNormalizedObject=function(){var a={};var b;a.summary="com.cubeia.games.poker.io.protocol.PlayerSitoutRequest";a.details={};a.details.player=this.player;return a}};com.cubeia.games.poker.io.protocol.PlayerSitoutRequest.CLASSID=34;