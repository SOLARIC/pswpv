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

public class Pot : ProtocolObject {
    public const int CLASSID = 26;

    public byte classId() {
        return CLASSID;
    }

    public byte id;
    public Enums.PotType type = Enums.makePotType(0);
    public int amount;

    /**
     * Default constructor.
     *
     */
    public Pot() {
        // Nothing here
    }

    public Pot(byte id, Enums.PotType type, int amount) {
        this.id = id;
        this.type = type;
        this.amount = amount;
    }

    public void save(PacketOutputStream ps) {
        ps.saveByte(id);
        ps.saveUnsignedByte((byte)type);
        ps.saveInt(amount);
    }

    public void load(PacketInputStream ps) {
        id = ps.loadByte();
        type = Enums.makePotType(ps.loadUnsignedByte());
        amount = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("Pot :");
        result.Append(" id["+id+"]");
        result.Append(" type["+type+"]");
        result.Append(" amount["+amount+"]");
        return result.ToString();
    }

}
}