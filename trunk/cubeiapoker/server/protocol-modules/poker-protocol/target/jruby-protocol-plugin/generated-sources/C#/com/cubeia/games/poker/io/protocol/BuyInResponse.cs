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

public class BuyInResponse : ProtocolObject {
    public const int CLASSID = 25;

    public byte classId() {
        return CLASSID;
    }

    public int balance;
    public int pendingBalance;
    public int amountBroughtIn;
    public Enums.BuyInResultCode resultCode = Enums.makeBuyInResultCode(0);

    /**
     * Default constructor.
     *
     */
    public BuyInResponse() {
        // Nothing here
    }

    public BuyInResponse(int balance, int pendingBalance, int amountBroughtIn, Enums.BuyInResultCode resultCode) {
        this.balance = balance;
        this.pendingBalance = pendingBalance;
        this.amountBroughtIn = amountBroughtIn;
        this.resultCode = resultCode;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(balance);
        ps.saveInt(pendingBalance);
        ps.saveInt(amountBroughtIn);
        ps.saveUnsignedByte((byte)resultCode);
    }

    public void load(PacketInputStream ps) {
        balance = ps.loadInt();
        pendingBalance = ps.loadInt();
        amountBroughtIn = ps.loadInt();
        resultCode = Enums.makeBuyInResultCode(ps.loadUnsignedByte());
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("BuyInResponse :");
        result.Append(" balance["+balance+"]");
        result.Append(" pending_balance["+pendingBalance+"]");
        result.Append(" amount_brought_in["+amountBroughtIn+"]");
        result.Append(" result_code["+resultCode+"]");
        return result.ToString();
    }

}
}