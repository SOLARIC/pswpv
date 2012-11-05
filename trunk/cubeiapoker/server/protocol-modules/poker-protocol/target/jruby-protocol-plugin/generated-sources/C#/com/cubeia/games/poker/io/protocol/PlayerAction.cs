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

public class PlayerAction : ProtocolObject {
    public const int CLASSID = 1;

    public byte classId() {
        return CLASSID;
    }

    public Enums.ActionType type = Enums.makeActionType(0);
    public int minAmount;
    public int maxAmount;

    /**
     * Default constructor.
     *
     */
    public PlayerAction() {
        // Nothing here
    }

    public PlayerAction(Enums.ActionType type, int minAmount, int maxAmount) {
        this.type = type;
        this.minAmount = minAmount;
        this.maxAmount = maxAmount;
    }

    public void save(PacketOutputStream ps) {
        ps.saveUnsignedByte((byte)type);
        ps.saveInt(minAmount);
        ps.saveInt(maxAmount);
    }

    public void load(PacketInputStream ps) {
        type = Enums.makeActionType(ps.loadUnsignedByte());
        minAmount = ps.loadInt();
        maxAmount = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerAction :");
        result.Append(" type["+type+"]");
        result.Append(" min_amount["+minAmount+"]");
        result.Append(" max_amount["+maxAmount+"]");
        return result.ToString();
    }

}
}