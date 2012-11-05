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

public final class StopHandHistory implements ProtocolObject, Visitable {
    public int classId() {
        return 18;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }

    /**
     * Default constructor.
     *
     */
    public StopHandHistory() {
        // Nothing here
    }

    public void save(PacketOutputStream ps) throws IOException {
    }

    public void load(PacketInputStream ps) throws IOException {
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("StopHandHistory :");
        return result.toString();
    }

}
