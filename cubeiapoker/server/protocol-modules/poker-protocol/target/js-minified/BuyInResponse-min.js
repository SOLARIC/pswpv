com.cubeia.games.poker.io.protocol.BuyInResponse=function(){this.classId=function(){return com.cubeia.games.poker.io.protocol.BuyInResponse.CLASSID};this.balance={};this.pendingBalance={};this.amountBroughtIn={};this.resultCode={};this.save=function(){var a=new FIREBASE.ByteArray();a.writeInt(this.balance);a.writeInt(this.pendingBalance);a.writeInt(this.amountBroughtIn);a.writeUnsignedByte(this.resultCode);return a};this.load=function(a){this.balance=a.readInt();this.pendingBalance=a.readInt();this.amountBroughtIn=a.readInt();this.resultCode=com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.makeBuyInResultCodeEnum(a.readUnsignedByte())};this.getNormalizedObject=function(){var a={};var b;a.summary="com.cubeia.games.poker.io.protocol.BuyInResponse";a.details={};a.details.balance=this.balance;a.details.pendingBalance=this.pendingBalance;a.details.amountBroughtIn=this.amountBroughtIn;a.details.resultCode=com.cubeia.games.poker.io.protocol.BuyInResultCodeEnum.toString(this.resultCode);return a}};com.cubeia.games.poker.io.protocol.BuyInResponse.CLASSID=25;