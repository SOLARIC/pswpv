com.cubeia.games.poker.io.protocol.DeckInfo=function(){this.classId=function(){return com.cubeia.games.poker.io.protocol.DeckInfo.CLASSID};this.size={};this.rankLow={};this.save=function(){var a=new FIREBASE.ByteArray();a.writeInt(this.size);a.writeUnsignedByte(this.rankLow);return a};this.load=function(a){this.size=a.readInt();this.rankLow=com.cubeia.games.poker.io.protocol.RankEnum.makeRankEnum(a.readUnsignedByte())};this.getNormalizedObject=function(){var a={};var b;a.summary="com.cubeia.games.poker.io.protocol.DeckInfo";a.details={};a.details.size=this.size;a.details.rankLow=com.cubeia.games.poker.io.protocol.RankEnum.toString(this.rankLow);return a}};com.cubeia.games.poker.io.protocol.DeckInfo.CLASSID=35;