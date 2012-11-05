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

public class PerformAction : ProtocolObject {
    public const int CLASSID = 19;

    public byte classId() {
        return CLASSID;
    }

    public int seq;
    public int player;
    public PlayerAction action;
    public int betAmount;
    public int raiseAmount;
    public int stackAmount;
    public bool timeout;

    /**
     * Default constructor.
     *
     */
    public PerformAction() {
        // Nothing here
    }

    public PerformAction(int seq, int player, PlayerAction action, int betAmount, int raiseAmount, int stackAmount, bool timeout) {
        this.seq = seq;
        this.player = player;
        this.action = action;
        this.betAmount = betAmount;
        this.raiseAmount = raiseAmount;
        this.stackAmount = stackAmount;
        this.timeout = timeout;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(seq);
        ps.saveInt(player);
        action.save(ps);
        ps.saveInt(betAmount);
        ps.saveInt(raiseAmount);
        ps.saveInt(stackAmount);
        ps.saveBool(timeout);
    }

    public void load(PacketInputStream ps) {
        seq = ps.loadInt();
        player = ps.loadInt();
        action = new PlayerAction();
        action.load(ps);
        betAmount = ps.loadInt();
        raiseAmount = ps.loadInt();
        stackAmount = ps.loadInt();
        timeout = ps.loadBool();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PerformAction :");
        result.Append(" seq["+seq+"]");
        result.Append(" player["+player+"]");
        result.Append(" action["+action+"]");
        result.Append(" bet_amount["+betAmount+"]");
        result.Append(" raise_amount["+raiseAmount+"]");
        result.Append(" stack_amount["+stackAmount+"]");
        result.Append(" timeout["+timeout+"]");
        return result.ToString();
    }

}
}