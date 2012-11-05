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

public final class PlayerAction implements ProtocolObject, Visitable {
    public int classId() {
        return 1;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public Enums.ActionType type = Enums.makeActionType(0);
    public int minAmount;
    public int maxAmount;

    /**
     * Default constructor.
     *
     */
    public PlayerAction() {
        // Nothing here
    }

    public PlayerAction(Enums.ActionType type, int minAmount, int maxAmount) {
        this.type = type;
        this.minAmount = minAmount;
        this.maxAmount = maxAmount;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveUnsignedByte(type.ordinal());
        ps.saveInt(minAmount);
        ps.saveInt(maxAmount);
    }

    public void load(PacketInputStream ps) throws IOException {
        type = Enums.makeActionType(ps.loadUnsignedByte());
        minAmount = ps.loadInt();
        maxAmount = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PlayerAction :");
        result.append(" type["+type+"]");
        result.append(" min_amount["+minAmount+"]");
        result.append(" max_amount["+maxAmount+"]");
        return result.toString();
    }

}
