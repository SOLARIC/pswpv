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

public class PlayerState : ProtocolObject {
    public const int CLASSID = 6;

    public byte classId() {
        return CLASSID;
    }

    public int player;
    public List<GameCard> cards = new List<GameCard>();
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

    public void save(PacketOutputStream ps) {
        ps.saveInt(player);
        if (cards == null) {
            ps.saveInt(0);
        } else {
            GameCard[] gameCardArray = cards.ToArray();
            ps.saveInt(gameCardArray.Length);
            foreach(GameCard gameCardObject in gameCardArray) {
                gameCardObject.save(ps);
            }
        }
        ps.saveInt(balance);
    }

    public void load(PacketInputStream ps) {
        player = ps.loadInt();
        int cardsCount = ps.loadInt();
        cards = new List<GameCard>(cardsCount);
        for(int i = 0; i != cardsCount; ++i) {
            GameCard _tmp = new GameCard();
            _tmp.load(ps);
            cards.Add(_tmp);
        }
        balance = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerState :");
        result.Append(" player["+player+"]");
        result.Append(" cards["+cards+"]");
        result.Append(" balance["+balance+"]");
        return result.ToString();
    }

}
}