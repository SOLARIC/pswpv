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

public class BestHand : ProtocolObject {
    public const int CLASSID = 5;

    public byte classId() {
        return CLASSID;
    }

    public int player;
    public Enums.HandType handType = Enums.makeHandType(0);
    public List<GameCard> cards = new List<GameCard>();

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

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
        ps.saveUnsignedByte((byte)handType);
        if (cards == null) {
            ps.saveInt(0);
        } else {
            GameCard[] gameCardArray = cards.ToArray();
            ps.saveInt(gameCardArray.Length);
            foreach(GameCard gameCardObject in gameCardArray) {
                gameCardObject.save(ps);
            }
        }
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
        handType = Enums.makeHandType(ps.loadUnsignedByte());
        int cardsCount = ps.loadInt();
        cards = new List<GameCard>(cardsCount);
        for(int i = 0; i != cardsCount; ++i) {
            GameCard _tmp = new GameCard();
            _tmp.load(ps);
            cards.Add(_tmp);
        }
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("BestHand :");
        result.Append(" player["+player+"]");
        result.Append(" hand_type["+handType+"]");
        result.Append(" cards["+cards+"]");
        return result.ToString();
    }

}
}