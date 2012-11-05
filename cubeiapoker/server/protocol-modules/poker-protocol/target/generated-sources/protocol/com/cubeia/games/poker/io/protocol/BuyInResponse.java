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

public final class BuyInResponse implements ProtocolObject, Visitable {
    public int classId() {
        return 25;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
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

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(balance);
        ps.saveInt(pendingBalance);
        ps.saveInt(amountBroughtIn);
        ps.saveUnsignedByte(resultCode.ordinal());
    }

    public void load(PacketInputStream ps) throws IOException {
        balance = ps.loadInt();
        pendingBalance = ps.loadInt();
        amountBroughtIn = ps.loadInt();
        resultCode = Enums.makeBuyInResultCode(ps.loadUnsignedByte());
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("BuyInResponse :");
        result.append(" balance["+balance+"]");
        result.append(" pending_balance["+pendingBalance+"]");
        result.append(" amount_brought_in["+amountBroughtIn+"]");
        result.append(" result_code["+resultCode+"]");
        return result.toString();
    }

}
