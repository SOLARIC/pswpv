com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket=function(){this.classId=function(){return com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket.CLASSID};this.playerId={};this.save=function(){var a=new FIREBASE.ByteArray();a.writeInt(this.playerId);return a};this.load=function(a){this.playerId=a.readInt()};this.getNormalizedObject=function(){var a={};var b;a.summary="com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket";a.details={};a.details.playerId=this.playerId;return a}};com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket.CLASSID=38;