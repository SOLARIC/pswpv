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

public final class CardToDeal implements ProtocolObject, Visitable {
    public int classId() {
        return 7;
    }

    public void accept(ProtocolObjectVisitor visitor) {
        if (visitor instanceof PacketVisitor) {
            PacketVisitor handler = (PacketVisitor) visitor;
            handler.visit(this);
        }
    }
    public int player;
    public GameCard card;

    /**
     * Default constructor.
     *
     */
    public CardToDeal() {
        // Nothing here
    }

    public CardToDeal(int player, GameCard card) {
        this.player = player;
        this.card = card;
    }

    public void save(PacketOutputStream ps) throws IOException {
        ps.saveInt(player);
        card.save(ps);
    }

    public void load(PacketInputStream ps) throws IOException {
        player = ps.loadInt();
        card = new GameCard();
        card.load(ps);
    }
    

    @Override

    public String toString() {
        StringBuilder result = new StringBuilder("CardToDeal :");
        result.append(" player["+player+"]");
        result.append(" card["+card+"]");
        return result.toString();
    }

}
