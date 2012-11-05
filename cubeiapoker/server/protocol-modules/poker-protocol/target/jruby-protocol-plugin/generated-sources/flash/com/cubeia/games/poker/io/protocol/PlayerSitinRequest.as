// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)
package com.cubeia.games.poker.io.protocol {

    import com.cubeia.firebase.io.PacketInputStream;
    import com.cubeia.firebase.io.PacketOutputStream;
    import com.cubeia.firebase.io.ProtocolObject;
  
    import flash.utils.ByteArray;

    public class PlayerSitinRequest implements ProtocolObject {
        public static const CLASSID:int = 33;

        public function classId():int {
            return PlayerSitinRequest.CLASSID;
        }

        public var player:int;

        /**
         * Default constructor.
         *
         */
        public function PlayerSitinRequest() {
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
            var result:String = "PlayerSitinRequest :";
            result += " player["+player+"]" ;
            return result;
        }

    }
}

// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

