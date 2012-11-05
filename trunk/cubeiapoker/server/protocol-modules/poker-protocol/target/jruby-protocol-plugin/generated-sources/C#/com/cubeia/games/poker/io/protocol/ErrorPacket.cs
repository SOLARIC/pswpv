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

public class ErrorPacket : ProtocolObject {
    public const int CLASSID = 2;

    public byte classId() {
        return CLASSID;
    }

    public Enums.ErrorCode code = Enums.makeErrorCode(0);
    public string referenceId;

    /**
     * Default constructor.
     *
     */
    public ErrorPacket() {
        // Nothing here
    }

    public ErrorPacket(Enums.ErrorCode code, string referenceId) {
        this.code = code;
        this.referenceId = referenceId;
    }

    public void save(PacketOutputStream ps) {
        ps.saveUnsignedByte((byte)code);
        ps.saveString(referenceId);
    }

    public void load(PacketInputStream ps) {
        code = Enums.makeErrorCode(ps.loadUnsignedByte());
        referenceId = ps.loadString();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("ErrorPacket :");
        result.Append(" code["+code+"]");
        result.Append(" reference_id["+referenceId+"]");
        return result.ToString();
    }

}
}