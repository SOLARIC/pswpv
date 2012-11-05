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

public final class PotTransfer implements ProtocolObject, Visitable {
    public int classId() {
        return 27;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public byte potId;
    public int playerId;
    public int amount;

    /**
     * Default constructor.
     *
     */
    public PotTransfer() {
        // Nothing here
    }

    public PotTransfer(byte potId, int playerId, int amount) {
        this.potId = potId;
        this.playerId = playerId;
        this.amount = amount;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveByte(potId);
        ps.saveInt(playerId);
        ps.saveInt(amount);
    }

    public void load(PacketInputStream ps) throws IOException {
        potId = ps.loadByte();
        playerId = ps.loadInt();
        amount = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PotTransfer :");
        result.append(" pot_id["+potId+"]");
        result.append(" player_id["+playerId+"]");
        result.append(" amount["+amount+"]");
        return result.toString();
    }

}
