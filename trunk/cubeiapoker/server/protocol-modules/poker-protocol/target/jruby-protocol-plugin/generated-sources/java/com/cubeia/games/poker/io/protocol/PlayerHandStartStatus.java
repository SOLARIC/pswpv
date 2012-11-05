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

public final class PlayerHandStartStatus implements ProtocolObject, Visitable {
    public int classId() {
        return 32;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int player;
    public Enums.PlayerTableStatus status = Enums.makePlayerTableStatus(0);

    /**
     * Default constructor.
     *
     */
    public PlayerHandStartStatus() {
        // Nothing here
    }

    public PlayerHandStartStatus(int player, Enums.PlayerTableStatus status) {
        this.player = player;
        this.status = status;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(player);
        ps.saveUnsignedByte(status.ordinal());
    }

    public void load(PacketInputStream ps) throws IOException {
        player = ps.loadInt();
        status = Enums.makePlayerTableStatus(ps.loadUnsignedByte());
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PlayerHandStartStatus :");
        result.append(" player["+player+"]");
        result.append(" status["+status+"]");
        return result.toString();
    }

}
