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

public class PlayerBalance : ProtocolObject {
    public const int CLASSID = 21;

    public byte classId() {
        return CLASSID;
    }

    public int balance;
    public int pendingBalance;
    public int player;
    public int playersContributionToPot;

    /**
     * Default constructor.
     *
     */
    public PlayerBalance() {
        // Nothing here
    }

    public PlayerBalance(int balance, int pendingBalance, int player, int playersContributionToPot) {
        this.balance = balance;
        this.pendingBalance = pendingBalance;
        this.player = player;
        this.playersContributionToPot = playersContributionToPot;
    }

    public void save(PacketOutputStream ps) {
        ps.saveInt(balance);
        ps.saveInt(pendingBalance);
        ps.saveInt(player);
        ps.saveInt(playersContributionToPot);
    }

    public void load(PacketInputStream ps) {
        balance = ps.loadInt();
        pendingBalance = ps.loadInt();
        player = ps.loadInt();
        playersContributionToPot = ps.loadInt();
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PlayerBalance :");
        result.Append(" balance["+balance+"]");
        result.Append(" pendingBalance["+pendingBalance+"]");
        result.Append(" player["+player+"]");
        result.Append(" players_contribution_to_pot["+playersContributionToPot+"]");
        return result.ToString();
    }

}
}