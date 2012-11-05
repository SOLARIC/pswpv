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

public class BuyInInfoResponse : ProtocolObject {
    public const int CLASSID = 23;

    public byte classId() {
        return CLASSID;
    }

    public int maxAmount;
    public int minAmount;
    public int balanceInWallet;
    public int balanceOnTable;
    public bool mandatoryBuyin;
    public Enums.BuyInInfoResultCode resultCode = Enums.makeBuyInInfoResultCode(0);

    /**
     * Default constructor.
     *
     */
    public BuyInInfoResponse() {
        // Nothing here
    }

    public BuyInInfoResponse(int maxAmount, int minAmount, int balanceInWallet, int balanceOnTable, bool mandatoryBuyin, Enums.BuyInInfoResultCode resultCode) {
        this.maxAmount = maxAmount;
        this.minAmount = minAmount;
        this.balanceInWallet = balanceInWallet;
        this.balanceOnTable = balanceOnTable;
        this.mandatoryBuyin = mandatoryBuyin;
        this.resultCode = resultCode;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(maxAmount);
        ps.saveInt(minAmount);
        ps.saveInt(balanceInWallet);
        ps.saveInt(balanceOnTable);
        ps.saveBool(mandatoryBuyin);
        ps.saveUnsignedByte((byte)resultCode);
    }

    public void load(PacketInputStream ps) {
        maxAmount = ps.loadInt();
        minAmount = ps.loadInt();
        balanceInWallet = ps.loadInt();
        balanceOnTable = ps.loadInt();
        mandatoryBuyin = ps.loadBool();
        resultCode = Enums.makeBuyInInfoResultCode(ps.loadUnsignedByte());
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("BuyInInfoResponse :");
        result.Append(" max_amount["+maxAmount+"]");
        result.Append(" min_amount["+minAmount+"]");
        result.Append(" balance_in_wallet["+balanceInWallet+"]");
        result.Append(" balance_on_table["+balanceOnTable+"]");
        result.Append(" mandatory_buyin["+mandatoryBuyin+"]");
        result.Append(" result_code["+resultCode+"]");
        return result.ToString();
    }

}
}