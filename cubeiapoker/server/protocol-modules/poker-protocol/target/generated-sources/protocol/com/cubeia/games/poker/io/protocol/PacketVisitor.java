// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)
package com.cubeia.games.poker.io.protocol;

import com.cubeia.firebase.io.PacketInputStream;
import com.cubeia.firebase.io.PacketOutputStream;
import com.cubeia.firebase.io.ProtocolObject;
import com.cubeia.firebase.io.ProtocolObjectVisitor;
import com.cubeia.firebase.io.Visitable;
import com.cubeia.firebase.styx.util.ArrayUtils;

import java.util.List;
import java.util.ArrayList;
import java.io.IOException;

public interface PacketVisitor extends ProtocolObjectVisitor {
    public void visit(PlayerAction packet);
    public void visit(ErrorPacket packet);
    public void visit(FuturePlayerAction packet);
    public void visit(GameCard packet);
    public void visit(BestHand packet);
    public void visit(PlayerState packet);
    public void visit(CardToDeal packet);
    public void visit(RequestAction packet);
    public void visit(InformFutureAllowedActions packet);
    public void visit(StartNewHand packet);
    public void visit(DealerButton packet);
    public void visit(DealPublicCards packet);
    public void visit(DealPrivateCards packet);
    public void visit(ExposePrivateCards packet);
    public void visit(HandEnd packet);
    public void visit(HandCanceled packet);
    public void visit(StartHandHistory packet);
    public void visit(StopHandHistory packet);
    public void visit(PerformAction packet);
    public void visit(TournamentOut packet);
    public void visit(PlayerBalance packet);
    public void visit(BuyInInfoRequest packet);
    public void visit(BuyInInfoResponse packet);
    public void visit(BuyInRequest packet);
    public void visit(BuyInResponse packet);
    public void visit(Pot packet);
    public void visit(PotTransfer packet);
    public void visit(PotTransfers packet);
    public void visit(TakeBackUncalledBet packet);
    public void visit(RakeInfo packet);
    public void visit(PlayerPokerStatus packet);
    public void visit(PlayerHandStartStatus packet);
    public void visit(PlayerSitinRequest packet);
    public void visit(PlayerSitoutRequest packet);
    public void visit(DeckInfo packet);
    public void visit(ExternalSessionInfoPacket packet);
    public void visit(PlayerDisconnectedPacket packet);
    public void visit(PlayerReconnectedPacket packet);
    public void visit(PingPacket packet);
    public void visit(PongPacket packet);
}
