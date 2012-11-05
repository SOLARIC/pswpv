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

public final class PotTransfers implements ProtocolObject, Visitable {
    public int classId() {
        return 28;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public boolean fromPlayerToPot;
    public List<PotTransfer> transfers;
    public List<Pot> pots;

    /**
     * Default constructor.
     *
     */
    public PotTransfers() {
        // Nothing here
    }

    public PotTransfers(boolean fromPlayerToPot, List<PotTransfer> transfers, List<Pot> pots) {
        this.fromPlayerToPot = fromPlayerToPot;
        this.transfers = transfers;
        this.pots = pots;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveBoolean(fromPlayerToPot);
        if (transfers == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(transfers.size());
            for(int i = 0; i != transfers.size(); ++i)
                transfers.get(i).save(ps);
        }
        if (pots == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(pots.size());
            for(int i = 0; i != pots.size(); ++i)
                pots.get(i).save(ps);
        }
    }

    public void load(PacketInputStream ps) throws IOException {
        fromPlayerToPot = ps.loadBoolean();
        int transfersCount = ps.loadInt();
        transfers = new ArrayList<PotTransfer>(transfersCount);
        for(int i = 0; i != transfersCount; ++i) {
            PotTransfer _tmp = new PotTransfer();
            _tmp.load(ps);
            transfers.add(_tmp);
        }
        int potsCount = ps.loadInt();
        pots = new ArrayList<Pot>(potsCount);
        for(int i = 0; i != potsCount; ++i) {
            Pot _tmp = new Pot();
            _tmp.load(ps);
            pots.add(_tmp);
        }
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PotTransfers :");
        result.append(" fromPlayerToPot["+fromPlayerToPot+"]");
        result.append(" transfers["+transfers+"]");
        result.append(" pots["+pots+"]");
        return result.toString();
    }

}
