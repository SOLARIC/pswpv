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

public final class PlayerState implements ProtocolObject, Visitable {
    public int classId() {
        return 6;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int player;
    public List<GameCard> cards;
    public int balance;

    /**
     * Default constructor.
     *
     */
    public PlayerState() {
        // Nothing here
    }

    public PlayerState(int player, List<GameCard> cards, int balance) {
        this.player = player;
        this.cards = cards;
        this.balance = balance;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(player);
        if (cards == null) {
            ps.saveInt(0);
        } else {
            ps.saveInt(cards.size());
            for(int i = 0; i != cards.size(); ++i)
                cards.get(i).save(ps);
        }
        ps.saveInt(balance);
    }

    public void load(PacketInputStream ps) throws IOException {
        player = ps.loadInt();
        int cardsCount = ps.loadInt();
        cards = new ArrayList<GameCard>(cardsCount);
        for(int i = 0; i != cardsCount; ++i) {
            GameCard _tmp = new GameCard();
            _tmp.load(ps);
            cards.add(_tmp);
        }
        balance = ps.loadInt();
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("PlayerState :");
        result.append(" player["+player+"]");
        result.append(" cards["+cards+"]");
        result.append(" balance["+balance+"]");
        return result.toString();
    }

}
