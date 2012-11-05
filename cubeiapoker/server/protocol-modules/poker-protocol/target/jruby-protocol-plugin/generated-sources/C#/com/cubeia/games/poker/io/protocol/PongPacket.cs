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

public class PongPacket : ProtocolObject {
    public const int CLASSID = 40;

    public byte classId() {
        return CLASSID;
    }

    public int identifier;

    /**
     * Default constructor.
     *
     */
    public PongPacket() {
        // Nothing here
    }

    public PongPacket(int identifier) {
        this.identifier = identifier;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(identifier);
    }

    public void load(PacketInputStream ps) {
        identifier = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PongPacket :");
        result.Append(" identifier["+identifier+"]");
        return result.ToString();
    }

}
}