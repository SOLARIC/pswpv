// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)
package com.cubeia.games.poker.io.protocol {

    import com.cubeia.firebase.io.PacketInputStream;
    import com.cubeia.firebase.io.PacketOutputStream;
    import com.cubeia.firebase.io.ProtocolObject;
  
    import flash.utils.ByteArray;

    public class PlayerSitoutRequest implements ProtocolObject {
        public static const CLASSID:int = 34;

        public function classId():int {
            return PlayerSitoutRequest.CLASSID;
        }

        public var player:int;

        /**
         * Default constructor.
         *
         */
        public function PlayerSitoutRequest() {
            // Nothing here
        }

        public function save():ByteArray
        {
            var buffer:ByteArray = new ByteArray();
            var ps:PacketOutputStream = new PacketOutputStream(buffer);
            ps.saveInt(player);
            return buffer;
        }

        public function load(buffer:ByteArray):void 
        {
            var ps:PacketInputStream = new PacketInputStream(buffer);
            player = ps.loadInt();
        }
        

        public function toString():String
        {
            var result:String = "PlayerSitoutRequest :";
            result += " player["+player+"]" ;
            return result;
        }

    }
}

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

