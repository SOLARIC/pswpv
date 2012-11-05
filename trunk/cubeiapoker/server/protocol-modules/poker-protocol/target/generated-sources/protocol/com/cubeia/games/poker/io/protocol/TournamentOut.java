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

public final class TournamentOut implements ProtocolObject, Visitable {
    public int classId() {
        return 20;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int player;
    public int position;

    /**
     * Default constructor.
     *
     */
    public TournamentOut() {
        // Nothing here
    }

    public TournamentOut(int player, int position) {
        this.player = player;
        this.position = position;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(player);
        ps.saveInt(position);
    }

    public void load(PacketInputStream ps) throws IOException {
        player = ps.loadInt();
        position = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("TournamentOut :");
        result.append(" player["+player+"]");
        result.append(" position["+position+"]");
        return result.toString();
    }

}
