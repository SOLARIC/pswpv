com.cubeia.games.poker.io.protocol.PingPacket=function(){this.classId=function(){return com.cubeia.games.poker.io.protocol.PingPacket.CLASSID};this.identifier={};this.save=function(){var a=new FIREBASE.ByteArray();a.writeInt(this.identifier);return a};this.load=function(a){this.identifier=a.readInt()};this.getNormalizedObject=function(){var a={};var b;a.summary="com.cubeia.games.poker.io.protocol.PingPacket";a.details={};a.details.identifier=this.identifier;return a}};com.cubeia.games.poker.io.protocol.PingPacket.CLASSID=39;