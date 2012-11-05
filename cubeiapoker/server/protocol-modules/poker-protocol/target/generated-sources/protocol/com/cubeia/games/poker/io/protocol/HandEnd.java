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

public final class HandEnd implements ProtocolObject, Visitable {
    public int classId() {
        return 15;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int[] playerIdRevealOrder = new int[0];
    public List<BestHand> hands;
    public PotTransfers potTransfers;

    /**
     * Default constructor.
     *
     */
    public HandEnd() {
        // Nothing here
    }

    public HandEnd(int[] playerIdRevealOrder, List<BestHand> hands, PotTransfers potTransfers) {
        this.playerIdRevealOrder = playerIdRevealOrder;
        this.hands = hands;
        this.potTransfers = potTransfers;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(playerIdRevealOrder.length);
        ps.saveArray(playerIdRevealOrder);
        if (hands == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(hands.size());
            for(int i = 0; i != hands.size(); ++i)
                hands.get(i).save(ps);
        }
        potTransfers.save(ps);
    }

    public void load(PacketInputStream ps) throws IOException {
        int playerIdRevealOrderCount = ps.loadInt();
        playerIdRevealOrder = new int[playerIdRevealOrderCount];
        ps.loadIntArray(playerIdRevealOrder);
        int handsCount = ps.loadInt();
        hands = new ArrayList<BestHand>(handsCount);
        for(int i = 0; i != handsCount; ++i) {
            BestHand _tmp = new BestHand();
            _tmp.load(ps);
            hands.add(_tmp);
        }
        potTransfers = new PotTransfers();
        potTransfers.load(ps);
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("HandEnd :");
        result.append(" player_id_reveal_order["+playerIdRevealOrder+"]");
        result.append(" hands["+hands+"]");
        result.append(" pot_transfers["+potTransfers+"]");
        return result.toString();
    }

}
