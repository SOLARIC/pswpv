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

public final class DealPublicCards implements ProtocolObject, Visitable {
    public int classId() {
        return 12;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public List<GameCard> cards;

    /**
     * Default constructor.
     *
     */
    public DealPublicCards() {
        // Nothing here
    }

    public DealPublicCards(List<GameCard> cards) {
        this.cards = cards;
    }

    public void save(PacketOutputStream ps) throws IOException {
        if (cards == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(cards.size());
            for(int i = 0; i != cards.size(); ++i)
                cards.get(i).save(ps);
        }
    }

    public void load(PacketInputStream ps) throws IOException {
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
        StringBuilder result = new StringBuilder("DealPublicCards :");
        result.append(" cards["+cards+"]");
        return result.toString();
    }

}
