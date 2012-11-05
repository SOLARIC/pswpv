// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERDISCONNECTEDPACKET_H_50CF6C01_INCLUDE
#define PLAYERDISCONNECTEDPACKET_H_50CF6C01_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerDisconnectedPacket : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 37;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player_id;
        int32_t timebank;

        PlayerDisconnectedPacket() {}

        PlayerDisconnectedPacket(int32_t player_id, int32_t timebank) {
            this->player_id = player_id;
            this->timebank = timebank;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerDisconnectedPacket &playerDisconnectedPacket)
        {
            packetOutputStream << playerDisconnectedPacket.player_id;
            packetOutputStream << playerDisconnectedPacket.timebank;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerDisconnectedPacket &playerDisconnectedPacket)
        {
            packetInputStream >> playerDisconnectedPacket.player_id;
            packetInputStream >> playerDisconnectedPacket.timebank;
            return packetInputStream;
        }

        virtual void load(const styx::StyxBuffer &buffer)
        {
            styx::PacketInputStream packetInputStream(buffer);
            packetInputStream >> *this;
        }

        virtual styx::StyxBuffer save(void) const
        {
            styx::PacketOutputStream packetOutputStream(CLASSID);
            packetOutputStream << *this;
            return packetOutputStream.packet();
        }
    };
}

#endif
