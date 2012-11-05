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

public final class RakeInfo implements ProtocolObject, Visitable {
    public int classId() {
        return 30;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int totalPot;
    public int totalRake;

    /**
     * Default constructor.
     *
     */
    public RakeInfo() {
        // Nothing here
    }

    public RakeInfo(int totalPot, int totalRake) {
        this.totalPot = totalPot;
        this.totalRake = totalRake;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(totalPot);
        ps.saveInt(totalRake);
    }

    public void load(PacketInputStream ps) throws IOException {
        totalPot = ps.loadInt();
        totalRake = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("RakeInfo :");
        result.append(" total_pot["+totalPot+"]");
        result.append(" total_rake["+totalRake+"]");
        return result.toString();
    }

}
