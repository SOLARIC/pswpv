com.cubeia.games.poker.io.protocol.ProtocolObjectFactory = {};

com.cubeia.games.poker.io.protocol.ProtocolObjectFactory.create = function(classId, gameData) {
    var protocolObject;
    switch(classId) {
        case com.cubeia.games.poker.io.protocol.PlayerAction.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerAction();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.ErrorPacket.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.ErrorPacket();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.FuturePlayerAction.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.FuturePlayerAction();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.GameCard.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.GameCard();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.BestHand.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.BestHand();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerState.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerState();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.CardToDeal.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.CardToDeal();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.RequestAction.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.RequestAction();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.InformFutureAllowedActions.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.InformFutureAllowedActions();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.StartNewHand.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.StartNewHand();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.DealerButton.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.DealerButton();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.DealPublicCards.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.DealPublicCards();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.DealPrivateCards.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.DealPrivateCards();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.ExposePrivateCards.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.ExposePrivateCards();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.HandEnd.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.HandEnd();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.HandCanceled.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.HandCanceled();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.StartHandHistory.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.StartHandHistory();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.StopHandHistory.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.StopHandHistory();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PerformAction.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PerformAction();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.TournamentOut.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.TournamentOut();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerBalance.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerBalance();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.BuyInInfoRequest.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.BuyInInfoRequest();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.BuyInInfoResponse.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.BuyInInfoResponse();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.BuyInRequest.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.BuyInRequest();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.BuyInResponse.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.BuyInResponse();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.Pot.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.Pot();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PotTransfer.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PotTransfer();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PotTransfers.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PotTransfers();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.TakeBackUncalledBet.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.TakeBackUncalledBet();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.RakeInfo.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.RakeInfo();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerPokerStatus.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerPokerStatus();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerHandStartStatus.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerHandStartStatus();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerSitinRequest.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerSitinRequest();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerSitoutRequest.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerSitoutRequest();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.DeckInfo.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.DeckInfo();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.ExternalSessionInfoPacket.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.ExternalSessionInfoPacket();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerDisconnectedPacket.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerDisconnectedPacket();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PlayerReconnectedPacket();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PingPacket.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PingPacket();
            protocolObject.load(gameData);
            return protocolObject;
        case com.cubeia.games.poker.io.protocol.PongPacket.CLASSID:
            protocolObject = new com.cubeia.games.poker.io.protocol.PongPacket();
            protocolObject.load(gameData);
            return protocolObject;
        }
    return null;
}

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

