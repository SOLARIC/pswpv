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

public class StartNewHand : ProtocolObject {
    public const int CLASSID = 10;

    public byte classId() {
        return CLASSID;
    }

    public int dealerSeatId;
    public string handId;

    /**
     * Default constructor.
     *
     */
    public StartNewHand() {
        // Nothing here
    }

    public StartNewHand(int dealerSeatId, string handId) {
        this.dealerSeatId = dealerSeatId;
        this.handId = handId;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(dealerSeatId);
        ps.saveString(handId);
    }

    public void load(PacketInputStream ps) {
        dealerSeatId = ps.loadInt();
        handId = ps.loadString();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("StartNewHand :");
        result.Append(" dealerSeatId["+dealerSeatId+"]");
        result.Append(" handId["+handId+"]");
        return result.ToString();
    }

}
}