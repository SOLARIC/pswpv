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

public class FuturePlayerAction : ProtocolObject {
    public const int CLASSID = 3;

    public byte classId() {
        return CLASSID;
    }

    public Enums.ActionType action = Enums.makeActionType(0);

    /**
     * Default constructor.
     *
     */
    public FuturePlayerAction() {
        // Nothing here
    }

    public FuturePlayerAction(Enums.ActionType action) {
        this.action = action;
    }

    public void save(PacketOutputStream ps) {
        ps.saveUnsignedByte((byte)action);
    }

    public void load(PacketInputStream ps) {
        action = Enums.makeActionType(ps.loadUnsignedByte());
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("FuturePlayerAction :");
        result.Append(" action["+action+"]");
        return result.ToString();
    }

}
}