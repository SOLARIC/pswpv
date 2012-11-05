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

public class RakeInfo : ProtocolObject {
    public const int CLASSID = 30;

    public byte classId() {
        return CLASSID;
    }

    public int totalPot;
    public int totalRake;

    /**
     * Default constructor.
     *
     */
    public RakeInfo() {
        // Nothing here
    }

    public RakeInfo(int totalPot, int totalRake) {
        this.totalPot = totalPot;
        this.totalRake = totalRake;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(totalPot);
        ps.saveInt(totalRake);
    }

    public void load(PacketInputStream ps) {
        totalPot = ps.loadInt();
        totalRake = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("RakeInfo :");
        result.Append(" total_pot["+totalPot+"]");
        result.Append(" total_rake["+totalRake+"]");
        return result.ToString();
    }

}
}