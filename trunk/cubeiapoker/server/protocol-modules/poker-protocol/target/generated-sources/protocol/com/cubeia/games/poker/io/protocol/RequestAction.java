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

public final class RequestAction implements ProtocolObject, Visitable {
    public int classId() {
        return 8;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int currentPotSize;
    public int seq;
    public int player;
    public List<PlayerAction> allowedActions;
    public int timeToAct;

    /**
     * Default constructor.
     *
     */
    public RequestAction() {
        // Nothing here
    }

    public RequestAction(int currentPotSize, int seq, int player, List<PlayerAction> allowedActions, int timeToAct) {
        this.currentPotSize = currentPotSize;
        this.seq = seq;
        this.player = player;
        this.allowedActions = allowedActions;
        this.timeToAct = timeToAct;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(currentPotSize);
        ps.saveInt(seq);
        ps.saveInt(player);
        if (allowedActions == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(allowedActions.size());
            for(int i = 0; i != allowedActions.size(); ++i)
                allowedActions.get(i).save(ps);
        }
        ps.saveInt(timeToAct);
    }

    public void load(PacketInputStream ps) throws IOException {
        currentPotSize = ps.loadInt();
        seq = ps.loadInt();
        player = ps.loadInt();
        int allowedActionsCount = ps.loadInt();
        allowedActions = new ArrayList<PlayerAction>(allowedActionsCount);
        for(int i = 0; i != allowedActionsCount; ++i) {
            PlayerAction _tmp = new PlayerAction();
            _tmp.load(ps);
            allowedActions.add(_tmp);
        }
        timeToAct = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("RequestAction :");
        result.append(" current_pot_size["+currentPotSize+"]");
        result.append(" seq["+seq+"]");
        result.append(" player["+player+"]");
        result.append(" allowed_actions["+allowedActions+"]");
        result.append(" time_to_act["+timeToAct+"]");
        return result.toString();
    }

}
