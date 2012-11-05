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

public class PlayerReconnectedPacket : ProtocolObject {
    public const int CLASSID = 38;

    public byte classId() {
        return CLASSID;
    }

    public int playerId;

    /**
     * Default constructor.
     *
     */
    public PlayerReconnectedPacket() {
        // Nothing here
    }

    public PlayerReconnectedPacket(int playerId) {
        this.playerId = playerId;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(playerId);
    }

    public void load(PacketInputStream ps) {
        playerId = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerReconnectedPacket :");
        result.Append(" player_id["+playerId+"]");
        return result.ToString();
    }

}
}