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

public final class ErrorPacket implements ProtocolObject, Visitable {
    public int classId() {
        return 2;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public Enums.ErrorCode code = Enums.makeErrorCode(0);
    public String referenceId;

    /**
     * Default constructor.
     *
     */
    public ErrorPacket() {
        // Nothing here
    }

    public ErrorPacket(Enums.ErrorCode code, String referenceId) {
        this.code = code;
        this.referenceId = referenceId;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveUnsignedByte(code.ordinal());
        ps.saveString(referenceId);
    }

    public void load(PacketInputStream ps) throws IOException {
        code = Enums.makeErrorCode(ps.loadUnsignedByte());
        referenceId = ps.loadString();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("ErrorPacket :");
        result.append(" code["+code+"]");
        result.append(" reference_id["+referenceId+"]");
        return result.toString();
    }

}
