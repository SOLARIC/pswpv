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

public final class BestHand implements ProtocolObject, Visitable {
    public int classId() {
        return 5;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int player;
    public Enums.HandType handType = Enums.makeHandType(0);
    public List<GameCard> cards;

    /**
     * Default constructor.
     *
     */
    public BestHand() {
        // Nothing here
    }

    public BestHand(int player, Enums.HandType handType, List<GameCard> cards) {
        this.player = player;
        this.handType = handType;
        this.cards = cards;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(player);
        ps.saveUnsignedByte(handType.ordinal());
        if (cards == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(cards.size());
            for(int i = 0; i != cards.size(); ++i)
                cards.get(i).save(ps);
        }
    }

    public void load(PacketInputStream ps) throws IOException {
        player = ps.loadInt();
        handType = Enums.makeHandType(ps.loadUnsignedByte());
        int cardsCount = ps.loadInt();
        cards = new ArrayList<GameCard>(cardsCount);
        for(int i = 0; i != cardsCount; ++i) {
            GameCard _tmp = new GameCard();
            _tmp.load(ps);
            cards.add(_tmp);
        }
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("BestHand :");
        result.append(" player["+player+"]");
        result.append(" hand_type["+handType+"]");
        result.append(" cards["+cards+"]");
        return result.toString();
    }

}
