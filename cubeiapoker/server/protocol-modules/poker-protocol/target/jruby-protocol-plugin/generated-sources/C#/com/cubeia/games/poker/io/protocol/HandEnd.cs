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

public class HandEnd : ProtocolObject {
    public const int CLASSID = 15;

    public byte classId() {
        return CLASSID;
    }

    public int[] playerIdRevealOrder = new int[0];
    public List<BestHand> hands = new List<BestHand>();
    public PotTransfers potTransfers;

    /**
     * Default constructor.
     *
     */
    public HandEnd() {
        // Nothing here
    }

    public HandEnd(int[] playerIdRevealOrder, List<BestHand> hands, PotTransfers potTransfers) {
        this.playerIdRevealOrder = playerIdRevealOrder;
        this.hands = hands;
        this.potTransfers = potTransfers;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(playerIdRevealOrder.Length);
        ps.saveArray(playerIdRevealOrder);
        if (hands == null) {
            ps.saveInt(0);
        } else {
            BestHand[] bestHandArray = hands.ToArray();
            ps.saveInt(bestHandArray.Length);
            foreach(BestHand bestHandObject in bestHandArray) {
                bestHandObject.save(ps);
            }
        }
        potTransfers.save(ps);
    }

    public void load(PacketInputStream ps) {
        int playerIdRevealOrderCount = ps.loadInt();
        playerIdRevealOrder = new int[playerIdRevealOrderCount];
        ps.loadIntArray(playerIdRevealOrder);
        int handsCount = ps.loadInt();
        hands = new List<BestHand>(handsCount);
        for(int i = 0; i != handsCount; ++i) {
            BestHand _tmp = new BestHand();
            _tmp.load(ps);
            hands.Add(_tmp);
        }
        potTransfers = new PotTransfers();
        potTransfers.load(ps);
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("HandEnd :");
        result.Append(" player_id_reveal_order["+playerIdRevealOrder+"]");
        result.Append(" hands["+hands+"]");
        result.Append(" pot_transfers["+potTransfers+"]");
        return result.ToString();
    }

}
}