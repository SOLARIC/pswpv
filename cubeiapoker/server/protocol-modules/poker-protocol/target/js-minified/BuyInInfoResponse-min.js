com.cubeia.games.poker.io.protocol.BuyInInfoResponse=function(){this.classId=function(){return com.cubeia.games.poker.io.protocol.BuyInInfoResponse.CLASSID};this.maxAmount={};this.minAmount={};this.balanceInWallet={};this.balanceOnTable={};this.mandatoryBuyin={};this.resultCode={};this.save=function(){var a=new FIREBASE.ByteArray();a.writeInt(this.maxAmount);a.writeInt(this.minAmount);a.writeInt(this.balanceInWallet);a.writeInt(this.balanceOnTable);a.writeBoolean(this.mandatoryBuyin);a.writeUnsignedByte(this.resultCode);return a};this.load=function(a){this.maxAmount=a.readInt();this.minAmount=a.readInt();this.balanceInWallet=a.readInt();this.balanceOnTable=a.readInt();this.mandatoryBuyin=a.readBoolean();this.resultCode=com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.makeBuyInInfoResultCodeEnum(a.readUnsignedByte())};this.getNormalizedObject=function(){var a={};var b;a.summary="com.cubeia.games.poker.io.protocol.BuyInInfoResponse";a.details={};a.details.maxAmount=this.maxAmount;a.details.minAmount=this.minAmount;a.details.balanceInWallet=this.balanceInWallet;a.details.balanceOnTable=this.balanceOnTable;a.details.mandatoryBuyin=this.mandatoryBuyin;a.details.resultCode=com.cubeia.games.poker.io.protocol.BuyInInfoResultCodeEnum.toString(this.resultCode);return a}};com.cubeia.games.poker.io.protocol.BuyInInfoResponse.CLASSID=23;