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

public class DealerButton : ProtocolObject {
    public const int CLASSID = 11;

    public byte classId() {
        return CLASSID;
    }

    public byte seat;

    /**
     * Default constructor.
     *
     */
    public DealerButton() {
        // Nothing here
    }

    public DealerButton(byte seat) {
        this.seat = seat;
    }

    public void save(PacketOutputStream ps) {
        ps.saveByte(seat);
    }

    public void load(PacketInputStream ps) {
        seat = ps.loadByte();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("DealerButton :");
        result.Append(" seat["+seat+"]");
        return result.ToString();
    }

}
}