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

public class PlayerDisconnectedPacket : ProtocolObject {
    public const int CLASSID = 37;

    public byte classId() {
        return CLASSID;
    }

    public int playerId;
    public int timebank;

    /**
     * Default constructor.
     *
     */
    public PlayerDisconnectedPacket() {
        // Nothing here
    }

    public PlayerDisconnectedPacket(int playerId, int timebank) {
        this.playerId = playerId;
        this.timebank = timebank;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(playerId);
        ps.saveInt(timebank);
    }

    public void load(PacketInputStream ps) {
        playerId = ps.loadInt();
        timebank = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerDisconnectedPacket :");
        result.Append(" player_id["+playerId+"]");
        result.Append(" timebank["+timebank+"]");
        return result.ToString();
    }

}
}