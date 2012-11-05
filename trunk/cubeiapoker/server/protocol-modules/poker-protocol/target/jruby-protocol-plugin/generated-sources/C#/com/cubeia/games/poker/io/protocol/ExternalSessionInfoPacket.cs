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

public class ExternalSessionInfoPacket : ProtocolObject {
    public const int CLASSID = 36;

    public byte classId() {
        return CLASSID;
    }

    public string externalTableReference;
    public string externalTableSessionReference;

    /**
     * Default constructor.
     *
     */
    public ExternalSessionInfoPacket() {
        // Nothing here
    }

    public ExternalSessionInfoPacket(string externalTableReference, string externalTableSessionReference) {
        this.externalTableReference = externalTableReference;
        this.externalTableSessionReference = externalTableSessionReference;
    }

    public void save(PacketOutputStream ps) {
        ps.saveString(externalTableReference);
        ps.saveString(externalTableSessionReference);
    }

    public void load(PacketInputStream ps) {
        externalTableReference = ps.loadString();
        externalTableSessionReference = ps.loadString();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("ExternalSessionInfoPacket :");
        result.Append(" external_table_reference["+externalTableReference+"]");
        result.Append(" external_table_session_reference["+externalTableSessionReference+"]");
        return result.ToString();
    }

}
}