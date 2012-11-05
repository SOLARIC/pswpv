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

public class CardToDeal : ProtocolObject {
    public const int CLASSID = 7;

    public byte classId() {
        return CLASSID;
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

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
        card.save(ps);
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
        card = new GameCard();
        card.load(ps);
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("CardToDeal :");
        result.Append(" player["+player+"]");
        result.Append(" card["+card+"]");
        return result.ToString();
    }

}
}