// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)
package com.cubeia.games.poker.io.protocol;

import com.cubeia.firebase.io.PacketInputStream;
import com.cubeia.firebase.io.PacketOutputStream;
import com.cubeia.firebase.io.ProtocolObject;
import com.cubeia.firebase.io.ProtocolObjectVisitor;
import com.cubeia.firebase.io.Visitable;
import com.cubeia.firebase.styx.util.ArrayUtils;

import java.util.List;
import java.util.ArrayList;
import java.io.IOException;

public final class BuyInInfoResponse implements ProtocolObject, Visitable {
    public int classId() {
        return 23;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int maxAmount;
    public int minAmount;
    public int balanceInWallet;
    public int balanceOnTable;
    public boolean mandatoryBuyin;
    public Enums.BuyInInfoResultCode resultCode = Enums.makeBuyInInfoResultCode(0);

    /**
     * Default constructor.
     *
     */
    public BuyInInfoResponse() {
        // Nothing here
    }

    public BuyInInfoResponse(int maxAmount, int minAmount, int balanceInWallet, int balanceOnTable, boolean mandatoryBuyin, Enums.BuyInInfoResultCode resultCode) {
        this.maxAmount = maxAmount;
        this.minAmount = minAmount;
        this.balanceInWallet = balanceInWallet;
        this.balanceOnTable = balanceOnTable;
        this.mandatoryBuyin = mandatoryBuyin;
        this.resultCode = resultCode;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(maxAmount);
        ps.saveInt(minAmount);
        ps.saveInt(balanceInWallet);
        ps.saveInt(balanceOnTable);
        ps.saveBoolean(mandatoryBuyin);
        ps.saveUnsignedByte(resultCode.ordinal());
    }

    public void load(PacketInputStream ps) throws IOException {
        maxAmount = ps.loadInt();
        minAmount = ps.loadInt();
        balanceInWallet = ps.loadInt();
        balanceOnTable = ps.loadInt();
        mandatoryBuyin = ps.loadBoolean();
        resultCode = Enums.makeBuyInInfoResultCode(ps.loadUnsignedByte());
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("BuyInInfoResponse :");
        result.append(" max_amount["+maxAmount+"]");
        result.append(" min_amount["+minAmount+"]");
        result.append(" balance_in_wallet["+balanceInWallet+"]");
        result.append(" balance_on_table["+balanceOnTable+"]");
        result.append(" mandatory_buyin["+mandatoryBuyin+"]");
        result.append(" result_code["+resultCode+"]");
        return result.toString();
    }

}
