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

public final class DealerButton implements ProtocolObject, Visitable {
    public int classId() {
        return 11;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public byte seat;

    /**
     * Default constructor.
     *
     */
    public DealerButton() {
        // Nothing here
    }

    public DealerButton(byte seat) {
        this.seat = seat;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveByte(seat);
    }

    public void load(PacketInputStream ps) throws IOException {
        seat = ps.loadByte();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("DealerButton :");
        result.append(" seat["+seat+"]");
        return result.toString();
    }

}
