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

public class PotTransfer : ProtocolObject {
    public const int CLASSID = 27;

    public byte classId() {
        return CLASSID;
    }

    public byte potId;
    public int playerId;
    public int amount;

    /**
     * Default constructor.
     *
     */
    public PotTransfer() {
        // Nothing here
    }

    public PotTransfer(byte potId, int playerId, int amount) {
        this.potId = potId;
        this.playerId = playerId;
        this.amount = amount;
    }

    public void save(PacketOutputStream ps) {
        ps.saveByte(potId);
        ps.saveInt(playerId);
        ps.saveInt(amount);
    }

    public void load(PacketInputStream ps) {
        potId = ps.loadByte();
        playerId = ps.loadInt();
        amount = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PotTransfer :");
        result.Append(" pot_id["+potId+"]");
        result.Append(" player_id["+playerId+"]");
        result.Append(" amount["+amount+"]");
        return result.ToString();
    }

}
}