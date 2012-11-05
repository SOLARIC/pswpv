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

public final class TakeBackUncalledBet implements ProtocolObject, Visitable {
    public int classId() {
        return 29;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int playerId;
    public int amount;

    /**
     * Default constructor.
     *
     */
    public TakeBackUncalledBet() {
        // Nothing here
    }

    public TakeBackUncalledBet(int playerId, int amount) {
        this.playerId = playerId;
        this.amount = amount;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(playerId);
        ps.saveInt(amount);
    }

    public void load(PacketInputStream ps) throws IOException {
        playerId = ps.loadInt();
        amount = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("TakeBackUncalledBet :");
        result.append(" player_id["+playerId+"]");
        result.append(" amount["+amount+"]");
        return result.toString();
    }

}
