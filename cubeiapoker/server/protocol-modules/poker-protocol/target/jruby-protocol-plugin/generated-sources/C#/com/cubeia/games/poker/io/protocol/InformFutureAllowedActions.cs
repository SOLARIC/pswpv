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

public class InformFutureAllowedActions : ProtocolObject {
    public const int CLASSID = 9;

    public byte classId() {
        return CLASSID;
    }

    public List<FuturePlayerAction> actions = new List<FuturePlayerAction>();

    /**
     * Default constructor.
     *
     */
    public InformFutureAllowedActions() {
        // Nothing here
    }

    public InformFutureAllowedActions(List<FuturePlayerAction> actions) {
        this.actions = actions;
    }

    public void save(PacketOutputStream ps) {
        if (actions == null) {
            ps.saveInt(0);
        } else {
            FuturePlayerAction[] futurePlayerActionArray = actions.ToArray();
            ps.saveInt(futurePlayerActionArray.Length);
            foreach(FuturePlayerAction futurePlayerActionObject in futurePlayerActionArray) {
                futurePlayerActionObject.save(ps);
            }
        }
    }

    public void load(PacketInputStream ps) {
        int actionsCount = ps.loadInt();
        actions = new List<FuturePlayerAction>(actionsCount);
        for(int i = 0; i != actionsCount; ++i) {
            FuturePlayerAction _tmp = new FuturePlayerAction();
            _tmp.load(ps);
            actions.Add(_tmp);
        }
    }
    

    override public String ToString() {
        StringBuilder result = new StringBuilder("InformFutureAllowedActions :");
        result.Append(" actions["+actions+"]");
        return result.ToString();
    }

}
}