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

public class HandCanceled : ProtocolObject {
    public const int CLASSID = 16;

    public byte classId() {
        return CLASSID;
    }


    /**
     * Default constructor.
     *
     */
    public HandCanceled() {
        // Nothing here
    }

    public void save(PacketOutputStream ps) {
    }

    public void load(PacketInputStream ps) {
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("HandCanceled :");
        return result.ToString();
    }

}
}