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

public final class FuturePlayerAction implements ProtocolObject, Visitable {
    public int classId() {
        return 3;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public Enums.ActionType action = Enums.makeActionType(0);

    /**
     * Default constructor.
     *
     */
    public FuturePlayerAction() {
        // Nothing here
    }

    public FuturePlayerAction(Enums.ActionType action) {
        this.action = action;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveUnsignedByte(action.ordinal());
    }

    public void load(PacketInputStream ps) throws IOException {
        action = Enums.makeActionType(ps.loadUnsignedByte());
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("FuturePlayerAction :");
        result.append(" action["+action+"]");
        return result.toString();
    }

}
