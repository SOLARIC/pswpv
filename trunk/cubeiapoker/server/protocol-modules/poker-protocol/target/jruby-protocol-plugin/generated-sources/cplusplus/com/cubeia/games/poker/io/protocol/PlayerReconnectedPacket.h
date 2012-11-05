// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERRECONNECTEDPACKET_H_45ED35B4_INCLUDE
#define PLAYERRECONNECTEDPACKET_H_45ED35B4_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerReconnectedPacket : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 38;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player_id;

        PlayerReconnectedPacket() {}

        PlayerReconnectedPacket(int32_t player_id) {
            this->player_id = player_id;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerReconnectedPacket &playerReconnectedPacket)
        {
            packetOutputStream << playerReconnectedPacket.player_id;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerReconnectedPacket &playerReconnectedPacket)
        {
            packetInputStream >> playerReconnectedPacket.player_id;
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
