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

public final class ExternalSessionInfoPacket implements ProtocolObject, Visitable {
    public int classId() {
        return 36;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public String externalTableReference;
    public String externalTableSessionReference;

    /**
     * Default constructor.
     *
     */
    public ExternalSessionInfoPacket() {
        // Nothing here
    }

    public ExternalSessionInfoPacket(String externalTableReference, String externalTableSessionReference) {
        this.externalTableReference = externalTableReference;
        this.externalTableSessionReference = externalTableSessionReference;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveString(externalTableReference);
        ps.saveString(externalTableSessionReference);
    }

    public void load(PacketInputStream ps) throws IOException {
        externalTableReference = ps.loadString();
        externalTableSessionReference = ps.loadString();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("ExternalSessionInfoPacket :");
        result.append(" external_table_reference["+externalTableReference+"]");
        result.append(" external_table_session_reference["+externalTableSessionReference+"]");
        return result.toString();
    }

}
