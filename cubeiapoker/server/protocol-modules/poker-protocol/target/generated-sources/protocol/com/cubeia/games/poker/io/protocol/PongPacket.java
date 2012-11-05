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

public final class PongPacket implements ProtocolObject, Visitable {
    public int classId() {
        return 40;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int identifier;

    /**
     * Default constructor.
     *
     */
    public PongPacket() {
        // Nothing here
    }

    public PongPacket(int identifier) {
        this.identifier = identifier;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(identifier);
    }

    public void load(PacketInputStream ps) throws IOException {
        identifier = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PongPacket :");
        result.append(" identifier["+identifier+"]");
        return result.toString();
    }

}
