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

public final class DeckInfo implements ProtocolObject, Visitable {
    public int classId() {
        return 35;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int size;
    public Enums.Rank rankLow = Enums.makeRank(0);

    /**
     * Default constructor.
     *
     */
    public DeckInfo() {
        // Nothing here
    }

    public DeckInfo(int size, Enums.Rank rankLow) {
        this.size = size;
        this.rankLow = rankLow;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(size);
        ps.saveUnsignedByte(rankLow.ordinal());
    }

    public void load(PacketInputStream ps) throws IOException {
        size = ps.loadInt();
        rankLow = Enums.makeRank(ps.loadUnsignedByte());
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("DeckInfo :");
        result.append(" size["+size+"]");
        result.append(" rank_low["+rankLow+"]");
        return result.toString();
    }

}
