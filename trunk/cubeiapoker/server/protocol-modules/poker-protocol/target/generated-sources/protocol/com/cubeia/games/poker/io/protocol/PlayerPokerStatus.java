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

public final class PlayerPokerStatus implements ProtocolObject, Visitable {
    public int classId() {
        return 31;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int player;
    public Enums.PlayerTableStatus status = Enums.makePlayerTableStatus(0);
    public boolean inCurrentHand;

    /**
     * Default constructor.
     *
     */
    public PlayerPokerStatus() {
        // Nothing here
    }

    public PlayerPokerStatus(int player, Enums.PlayerTableStatus status, boolean inCurrentHand) {
        this.player = player;
        this.status = status;
        this.inCurrentHand = inCurrentHand;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(player);
        ps.saveUnsignedByte(status.ordinal());
        ps.saveBoolean(inCurrentHand);
    }

    public void load(PacketInputStream ps) throws IOException {
        player = ps.loadInt();
        status = Enums.makePlayerTableStatus(ps.loadUnsignedByte());
        inCurrentHand = ps.loadBoolean();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PlayerPokerStatus :");
        result.append(" player["+player+"]");
        result.append(" status["+status+"]");
        result.append(" in_current_hand["+inCurrentHand+"]");
        return result.toString();
    }

}
