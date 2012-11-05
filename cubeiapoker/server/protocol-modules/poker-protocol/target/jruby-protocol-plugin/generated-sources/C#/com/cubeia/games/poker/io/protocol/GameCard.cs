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

public class GameCard : ProtocolObject {
    public const int CLASSID = 4;

    public byte classId() {
        return CLASSID;
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

    public void save(PacketOutputStream ps) {
        ps.saveInt(cardId);
        ps.saveUnsignedByte((byte)suit);
        ps.saveUnsignedByte((byte)rank);
    }

    public void load(PacketInputStream ps) {
        cardId = ps.loadInt();
        suit = Enums.makeSuit(ps.loadUnsignedByte());
        rank = Enums.makeRank(ps.loadUnsignedByte());
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("GameCard :");
        result.Append(" card_id["+cardId+"]");
        result.Append(" suit["+suit+"]");
        result.Append(" rank["+rank+"]");
        return result.ToString();
    }

}
}