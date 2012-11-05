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

public final class GameCard implements ProtocolObject, Visitable {
    public int classId() {
        return 4;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int cardId;
    public Enums.Suit suit = Enums.makeSuit(0);
    public Enums.Rank rank = Enums.makeRank(0);

    /**
     * Default constructor.
     *
     */
    public GameCard() {
        // Nothing here
    }

    public GameCard(int cardId, Enums.Suit suit, Enums.Rank rank) {
        this.cardId = cardId;
        this.suit = suit;
        this.rank = rank;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(cardId);
        ps.saveUnsignedByte(suit.ordinal());
        ps.saveUnsignedByte(rank.ordinal());
    }

    public void load(PacketInputStream ps) throws IOException {
        cardId = ps.loadInt();
        suit = Enums.makeSuit(ps.loadUnsignedByte());
        rank = Enums.makeRank(ps.loadUnsignedByte());
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("GameCard :");
        result.append(" card_id["+cardId+"]");
        result.append(" suit["+suit+"]");
        result.append(" rank["+rank+"]");
        return result.toString();
    }

}
