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

public class BuyInRequest : ProtocolObject {
    public const int CLASSID = 24;

    public byte classId() {
        return CLASSID;
    }

    public int amount;
    public bool sitInIfSuccessful;

    /**
     * Default constructor.
     *
     */
    public BuyInRequest() {
        // Nothing here
    }

    public BuyInRequest(int amount, bool sitInIfSuccessful) {
        this.amount = amount;
        this.sitInIfSuccessful = sitInIfSuccessful;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(amount);
        ps.saveBool(sitInIfSuccessful);
    }

    public void load(PacketInputStream ps) {
        amount = ps.loadInt();
        sitInIfSuccessful = ps.loadBool();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("BuyInRequest :");
        result.Append(" amount["+amount+"]");
        result.Append(" sit_in_if_successful["+sitInIfSuccessful+"]");
        return result.ToString();
    }

}
}