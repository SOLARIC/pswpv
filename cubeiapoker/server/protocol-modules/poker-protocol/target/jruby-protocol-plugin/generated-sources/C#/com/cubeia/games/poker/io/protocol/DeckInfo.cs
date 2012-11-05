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

public class DeckInfo : ProtocolObject {
    public const int CLASSID = 35;

    public byte classId() {
        return CLASSID;
    }

    public int size;
    public Enums.Rank rankLow = Enums.makeRank(0);

    /**
     * Default constructor.
     *
     */
    public DeckInfo() {
        // Nothing here
    }

    public DeckInfo(int size, Enums.Rank rankLow) {
        this.size = size;
        this.rankLow = rankLow;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(size);
        ps.saveUnsignedByte((byte)rankLow);
    }

    public void load(PacketInputStream ps) {
        size = ps.loadInt();
        rankLow = Enums.makeRank(ps.loadUnsignedByte());
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("DeckInfo :");
        result.Append(" size["+size+"]");
        result.Append(" rank_low["+rankLow+"]");
        return result.ToString();
    }

}
}