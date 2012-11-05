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

public final class PerformAction implements ProtocolObject, Visitable {
    public int classId() {
        return 19;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int seq;
    public int player;
    public PlayerAction action;
    public int betAmount;
    public int raiseAmount;
    public int stackAmount;
    public boolean timeout;

    /**
     * Default constructor.
     *
     */
    public PerformAction() {
        // Nothing here
    }

    public PerformAction(int seq, int player, PlayerAction action, int betAmount, int raiseAmount, int stackAmount, boolean timeout) {
        this.seq = seq;
        this.player = player;
        this.action = action;
        this.betAmount = betAmount;
        this.raiseAmount = raiseAmount;
        this.stackAmount = stackAmount;
        this.timeout = timeout;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(seq);
        ps.saveInt(player);
        action.save(ps);
        ps.saveInt(betAmount);
        ps.saveInt(raiseAmount);
        ps.saveInt(stackAmount);
        ps.saveBoolean(timeout);
    }

    public void load(PacketInputStream ps) throws IOException {
        seq = ps.loadInt();
        player = ps.loadInt();
        action = new PlayerAction();
        action.load(ps);
        betAmount = ps.loadInt();
        raiseAmount = ps.loadInt();
        stackAmount = ps.loadInt();
        timeout = ps.loadBoolean();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PerformAction :");
        result.append(" seq["+seq+"]");
        result.append(" player["+player+"]");
        result.append(" action["+action+"]");
        result.append(" bet_amount["+betAmount+"]");
        result.append(" raise_amount["+raiseAmount+"]");
        result.append(" stack_amount["+stackAmount+"]");
        result.append(" timeout["+timeout+"]");
        return result.toString();
    }

}
