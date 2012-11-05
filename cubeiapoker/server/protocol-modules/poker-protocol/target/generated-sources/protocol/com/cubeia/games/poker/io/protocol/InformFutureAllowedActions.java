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

public final class InformFutureAllowedActions implements ProtocolObject, Visitable {
    public int classId() {
        return 9;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public List<FuturePlayerAction> actions;

    /**
     * Default constructor.
     *
     */
    public InformFutureAllowedActions() {
        // Nothing here
    }

    public InformFutureAllowedActions(List<FuturePlayerAction> actions) {
        this.actions = actions;
    }

    public void save(PacketOutputStream ps) throws IOException {
        if (actions == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(actions.size());
            for(int i = 0; i != actions.size(); ++i)
                actions.get(i).save(ps);
        }
    }

    public void load(PacketInputStream ps) throws IOException {
        int actionsCount = ps.loadInt();
        actions = new ArrayList<FuturePlayerAction>(actionsCount);
        for(int i = 0; i != actionsCount; ++i) {
            FuturePlayerAction _tmp = new FuturePlayerAction();
            _tmp.load(ps);
            actions.add(_tmp);
        }
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("InformFutureAllowedActions :");
        result.append(" actions["+actions+"]");
        return result.toString();
    }

}
