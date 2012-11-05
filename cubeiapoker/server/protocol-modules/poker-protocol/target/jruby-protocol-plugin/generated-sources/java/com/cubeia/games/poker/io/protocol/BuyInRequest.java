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

public final class BuyInRequest implements ProtocolObject, Visitable {
    public int classId() {
        return 24;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int amount;
    public boolean sitInIfSuccessful;

    /**
     * Default constructor.
     *
     */
    public BuyInRequest() {
        // Nothing here
    }

    public BuyInRequest(int amount, boolean sitInIfSuccessful) {
        this.amount = amount;
        this.sitInIfSuccessful = sitInIfSuccessful;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(amount);
        ps.saveBoolean(sitInIfSuccessful);
    }

    public void load(PacketInputStream ps) throws IOException {
        amount = ps.loadInt();
        sitInIfSuccessful = ps.loadBoolean();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("BuyInRequest :");
        result.append(" amount["+amount+"]");
        result.append(" sit_in_if_successful["+sitInIfSuccessful+"]");
        return result.toString();
    }

}
