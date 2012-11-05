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

public class PlayerHandStartStatus : ProtocolObject {
    public const int CLASSID = 32;

    public byte classId() {
        return CLASSID;
    }

    public int player;
    public Enums.PlayerTableStatus status = Enums.makePlayerTableStatus(0);

    /**
     * Default constructor.
     *
     */
    public PlayerHandStartStatus() {
        // Nothing here
    }

    public PlayerHandStartStatus(int player, Enums.PlayerTableStatus status) {
        this.player = player;
        this.status = status;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
        ps.saveUnsignedByte((byte)status);
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
        status = Enums.makePlayerTableStatus(ps.loadUnsignedByte());
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerHandStartStatus :");
        result.Append(" player["+player+"]");
        result.Append(" status["+status+"]");
        return result.ToString();
    }

}
}