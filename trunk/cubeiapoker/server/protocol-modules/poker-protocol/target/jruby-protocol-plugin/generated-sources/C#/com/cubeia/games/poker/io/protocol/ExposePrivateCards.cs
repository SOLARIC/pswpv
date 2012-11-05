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

public class ExposePrivateCards : ProtocolObject {
    public const int CLASSID = 14;

    public byte classId() {
        return CLASSID;
    }

    public List<CardToDeal> cards = new List<CardToDeal>();

    /**
     * Default constructor.
     *
     */
    public ExposePrivateCards() {
        // Nothing here
    }

    public ExposePrivateCards(List<CardToDeal> cards) {
        this.cards = cards;
    }

    public void save(PacketOutputStream ps) {
        if (cards == null) {
            ps.saveInt(0);
        } else {
            CardToDeal[] cardToDealArray = cards.ToArray();
            ps.saveInt(cardToDealArray.Length);
            foreach(CardToDeal cardToDealObject in cardToDealArray) {
                cardToDealObject.save(ps);
            }
        }
    }

    public void load(PacketInputStream ps) {
        int cardsCount = ps.loadInt();
        cards = new List<CardToDeal>(cardsCount);
        for(int i = 0; i != cardsCount; ++i) {
            CardToDeal _tmp = new CardToDeal();
            _tmp.load(ps);
            cards.Add(_tmp);
        }
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("ExposePrivateCards :");
        result.Append(" cards["+cards+"]");
        return result.ToString();
    }

}
}