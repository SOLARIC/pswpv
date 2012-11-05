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

public class PlayerPokerStatus : ProtocolObject {
    public const int CLASSID = 31;

    public byte classId() {
        return CLASSID;
    }

    public int player;
    public Enums.PlayerTableStatus status = Enums.makePlayerTableStatus(0);
    public bool inCurrentHand;

    /**
     * Default constructor.
     *
     */
    public PlayerPokerStatus() {
        // Nothing here
    }

    public PlayerPokerStatus(int player, Enums.PlayerTableStatus status, bool inCurrentHand) {
        this.player = player;
        this.status = status;
        this.inCurrentHand = inCurrentHand;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
        ps.saveUnsignedByte((byte)status);
        ps.saveBool(inCurrentHand);
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
        status = Enums.makePlayerTableStatus(ps.loadUnsignedByte());
        inCurrentHand = ps.loadBool();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerPokerStatus :");
        result.Append(" player["+player+"]");
        result.Append(" status["+status+"]");
        result.Append(" in_current_hand["+inCurrentHand+"]");
        return result.ToString();
    }

}
}