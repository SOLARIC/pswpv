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

public final class StartNewHand implements ProtocolObject, Visitable {
    public int classId() {
        return 10;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int dealerSeatId;
    public String handId;

    /**
     * Default constructor.
     *
     */
    public StartNewHand() {
        // Nothing here
    }

    public StartNewHand(int dealerSeatId, String handId) {
        this.dealerSeatId = dealerSeatId;
        this.handId = handId;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(dealerSeatId);
        ps.saveString(handId);
    }

    public void load(PacketInputStream ps) throws IOException {
        dealerSeatId = ps.loadInt();
        handId = ps.loadString();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("StartNewHand :");
        result.append(" dealerSeatId["+dealerSeatId+"]");
        result.append(" handId["+handId+"]");
        return result.toString();
    }

}
