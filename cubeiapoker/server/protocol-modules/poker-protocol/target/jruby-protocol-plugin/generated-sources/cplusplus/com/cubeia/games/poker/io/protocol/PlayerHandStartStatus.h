// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERHANDSTARTSTATUS_H_7D53433A_INCLUDE
#define PLAYERHANDSTARTSTATUS_H_7D53433A_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerHandStartStatus : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 32;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;
        PlayerTableStatus::Enum status;

        PlayerHandStartStatus() {}

        PlayerHandStartStatus(int32_t player, PlayerTableStatus::Enum status) {
            this->player = player;
            this->status = status;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerHandStartStatus &playerHandStartStatus)
        {
            packetOutputStream << playerHandStartStatus.player;
            packetOutputStream << static_cast<uint8_t>(playerHandStartStatus.status);
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerHandStartStatus &playerHandStartStatus)
        {
            packetInputStream >> playerHandStartStatus.player;
            {
                uint8_t temp;
                packetInputStream >> temp;
                playerHandStartStatus.status = static_cast<PlayerTableStatus::Enum>(temp);
            }
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
