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

public class TournamentOut : ProtocolObject {
    public const int CLASSID = 20;

    public byte classId() {
        return CLASSID;
    }

    public int player;
    public int position;

    /**
     * Default constructor.
     *
     */
    public TournamentOut() {
        // Nothing here
    }

    public TournamentOut(int player, int position) {
        this.player = player;
        this.position = position;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
        ps.saveInt(position);
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
        position = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("TournamentOut :");
        result.Append(" player["+player+"]");
        result.Append(" position["+position+"]");
        return result.ToString();
    }

}
}