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

public class TakeBackUncalledBet : ProtocolObject {
    public const int CLASSID = 29;

    public byte classId() {
        return CLASSID;
    }

    public int playerId;
    public int amount;

    /**
     * Default constructor.
     *
     */
    public TakeBackUncalledBet() {
        // Nothing here
    }

    public TakeBackUncalledBet(int playerId, int amount) {
        this.playerId = playerId;
        this.amount = amount;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(playerId);
        ps.saveInt(amount);
    }

    public void load(PacketInputStream ps) {
        playerId = ps.loadInt();
        amount = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("TakeBackUncalledBet :");
        result.Append(" player_id["+playerId+"]");
        result.Append(" amount["+amount+"]");
        return result.ToString();
    }

}
}