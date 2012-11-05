// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net;
using Styx;

namespace com.cubeia.games.poker.io.protocol
{

public class ProtocolObjectFactory : ObjectFactory {
    public int version() {
        return 1;
    }

    public ProtocolObject create(int classId) {
        switch(classId) {
            case 1:
                return new PlayerAction();
            case 2:
                return new ErrorPacket();
            case 3:
                return new FuturePlayerAction();
            case 4:
                return new GameCard();
            case 5:
                return new BestHand();
            case 6:
                return new PlayerState();
            case 7:
                return new CardToDeal();
            case 8:
                return new RequestAction();
            case 9:
                return new InformFutureAllowedActions();
            case 10:
                return new StartNewHand();
            case 11:
                return new DealerButton();
            case 12:
                return new DealPublicCards();
            case 13:
                return new DealPrivateCards();
            case 14:
                return new ExposePrivateCards();
            case 15:
                return new HandEnd();
            case 16:
                return new HandCanceled();
            case 17:
                return new StartHandHistory();
            case 18:
                return new StopHandHistory();
            case 19:
                return new PerformAction();
            case 20:
                return new TournamentOut();
            case 21:
                return new PlayerBalance();
            case 22:
                return new BuyInInfoRequest();
            case 23:
                return new BuyInInfoResponse();
            case 24:
                return new BuyInRequest();
            case 25:
                return new BuyInResponse();
            case 26:
                return new Pot();
            case 27:
                return new PotTransfer();
            case 28:
                return new PotTransfers();
            case 29:
                return new TakeBackUncalledBet();
            case 30:
                return new RakeInfo();
            case 31:
                return new PlayerPokerStatus();
            case 32:
                return new PlayerHandStartStatus();
            case 33:
                return new PlayerSitinRequest();
            case 34:
                return new PlayerSitoutRequest();
            case 35:
                return new DeckInfo();
            case 36:
                return new ExternalSessionInfoPacket();
            case 37:
                return new PlayerDisconnectedPacket();
            case 38:
                return new PlayerReconnectedPacket();
            case 39:
                return new PingPacket();
            case 40:
                return new PongPacket();
        }
        throw new ArgumentOutOfRangeException("Unknown class id: " + classId);
    }
}
}