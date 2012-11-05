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

public class PlayerSitoutRequest : ProtocolObject {
    public const int CLASSID = 34;

    public byte classId() {
        return CLASSID;
    }

    public int player;

    /**
     * Default constructor.
     *
     */
    public PlayerSitoutRequest() {
        // Nothing here
    }

    public PlayerSitoutRequest(int player) {
        this.player = player;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerSitoutRequest :");
        result.Append(" player["+player+"]");
        return result.ToString();
    }

}
}