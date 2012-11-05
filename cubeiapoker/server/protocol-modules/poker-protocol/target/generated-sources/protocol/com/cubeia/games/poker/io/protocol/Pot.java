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

public final class Pot implements ProtocolObject, Visitable {
    public int classId() {
        return 26;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public byte id;
    public Enums.PotType type = Enums.makePotType(0);
    public int amount;

    /**
     * Default constructor.
     *
     */
    public Pot() {
        // Nothing here
    }

    public Pot(byte id, Enums.PotType type, int amount) {
        this.id = id;
        this.type = type;
        this.amount = amount;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveByte(id);
        ps.saveUnsignedByte(type.ordinal());
        ps.saveInt(amount);
    }

    public void load(PacketInputStream ps) throws IOException {
        id = ps.loadByte();
        type = Enums.makePotType(ps.loadUnsignedByte());
        amount = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("Pot :");
        result.append(" id["+id+"]");
        result.append(" type["+type+"]");
        result.append(" amount["+amount+"]");
        return result.toString();
    }

}
