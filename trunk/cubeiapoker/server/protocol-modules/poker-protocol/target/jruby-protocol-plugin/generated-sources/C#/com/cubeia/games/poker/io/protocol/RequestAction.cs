// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net;
using Styx;

namespace com.cubeia.games.poker.io.protocol
{

public class RequestAction : ProtocolObject {
    public const int CLASSID = 8;

    public byte classId() {
        return CLASSID;
    }

    public int currentPotSize;
    public int seq;
    public int player;
    public List<PlayerAction> allowedActions = new List<PlayerAction>();
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

    public void save(PacketOutputStream ps) {
        ps.saveInt(currentPotSize);
        ps.saveInt(seq);
        ps.saveInt(player);
        if (allowedActions == null) {
            ps.saveInt(0);
        } else {
            PlayerAction[] playerActionArray = allowedActions.ToArray();
            ps.saveInt(playerActionArray.Length);
            foreach(PlayerAction playerActionObject in playerActionArray) {
                playerActionObject.save(ps);
            }
        }
        ps.saveInt(timeToAct);
    }

    public void load(PacketInputStream ps) {
        currentPotSize = ps.loadInt();
        seq = ps.loadInt();
        player = ps.loadInt();
        int allowedActionsCount = ps.loadInt();
        allowedActions = new List<PlayerAction>(allowedActionsCount);
        for(int i = 0; i != allowedActionsCount; ++i) {
            PlayerAction _tmp = new PlayerAction();
            _tmp.load(ps);
            allowedActions.Add(_tmp);
        }
        timeToAct = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("RequestAction :");
        result.Append(" current_pot_size["+currentPotSize+"]");
        result.Append(" seq["+seq+"]");
        result.Append(" player["+player+"]");
        result.Append(" allowed_actions["+allowedActions+"]");
        result.Append(" time_to_act["+timeToAct+"]");
        return result.ToString();
    }

}
}