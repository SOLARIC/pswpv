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

public class DealPublicCards : ProtocolObject {
    public const int CLASSID = 12;

    public byte classId() {
        return CLASSID;
    }

    public List<GameCard> cards = new List<GameCard>();

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

    public void save(PacketOutputStream ps) {
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
        int cardsCount = ps.loadInt();
        cards = new List<GameCard>(cardsCount);
        for(int i = 0; i != cardsCount; ++i) {
            GameCard _tmp = new GameCard();
            _tmp.load(ps);
            cards.Add(_tmp);
        }
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("DealPublicCards :");
        result.Append(" cards["+cards+"]");
        return result.ToString();
    }

}
}