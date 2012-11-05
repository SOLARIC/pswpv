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

public final class PlayerBalance implements ProtocolObject, Visitable {
    public int classId() {
        return 21;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int balance;
    public int pendingBalance;
    public int player;
    public int playersContributionToPot;

    /**
     * Default constructor.
     *
     */
    public PlayerBalance() {
        // Nothing here
    }

    public PlayerBalance(int balance, int pendingBalance, int player, int playersContributionToPot) {
        this.balance = balance;
        this.pendingBalance = pendingBalance;
        this.player = player;
        this.playersContributionToPot = playersContributionToPot;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(balance);
        ps.saveInt(pendingBalance);
        ps.saveInt(player);
        ps.saveInt(playersContributionToPot);
    }

    public void load(PacketInputStream ps) throws IOException {
        balance = ps.loadInt();
        pendingBalance = ps.loadInt();
        player = ps.loadInt();
        playersContributionToPot = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PlayerBalance :");
        result.append(" balance["+balance+"]");
        result.append(" pendingBalance["+pendingBalance+"]");
        result.append(" player["+player+"]");
        result.append(" players_contribution_to_pot["+playersContributionToPot+"]");
        return result.toString();
    }

}
