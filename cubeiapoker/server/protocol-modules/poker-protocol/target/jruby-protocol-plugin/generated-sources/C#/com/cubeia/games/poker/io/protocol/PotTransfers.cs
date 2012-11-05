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

public class PotTransfers : ProtocolObject {
    public const int CLASSID = 28;

    public byte classId() {
        return CLASSID;
    }

    public bool fromPlayerToPot;
    public List<PotTransfer> transfers = new List<PotTransfer>();
    public List<Pot> pots = new List<Pot>();

    /**
     * Default constructor.
     *
     */
    public PotTransfers() {
        // Nothing here
    }

    public PotTransfers(bool fromPlayerToPot, List<PotTransfer> transfers, List<Pot> pots) {
        this.fromPlayerToPot = fromPlayerToPot;
        this.transfers = transfers;
        this.pots = pots;
    }

    public void save(PacketOutputStream ps) {
        ps.saveBool(fromPlayerToPot);
        if (transfers == null) {
            ps.saveInt(0);
        } else {
            PotTransfer[] potTransferArray = transfers.ToArray();
            ps.saveInt(potTransferArray.Length);
            foreach(PotTransfer potTransferObject in potTransferArray) {
                potTransferObject.save(ps);
            }
        }
        if (pots == null) {
            ps.saveInt(0);
        } else {
            Pot[] potArray = pots.ToArray();
            ps.saveInt(potArray.Length);
            foreach(Pot potObject in potArray) {
                potObject.save(ps);
            }
        }
    }

    public void load(PacketInputStream ps) {
        fromPlayerToPot = ps.loadBool();
        int transfersCount = ps.loadInt();
        transfers = new List<PotTransfer>(transfersCount);
        for(int i = 0; i != transfersCount; ++i) {
            PotTransfer _tmp = new PotTransfer();
            _tmp.load(ps);
            transfers.Add(_tmp);
        }
        int potsCount = ps.loadInt();
        pots = new List<Pot>(potsCount);
        for(int i = 0; i != potsCount; ++i) {
            Pot _tmp = new Pot();
            _tmp.load(ps);
            pots.Add(_tmp);
        }
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("PotTransfers :");
        result.Append(" fromPlayerToPot["+fromPlayerToPot+"]");
        result.Append(" transfers["+transfers+"]");
        result.Append(" pots["+pots+"]");
        return result.ToString();
    }

}
}