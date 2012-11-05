// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERPOKERSTATUS_H_3E424D10_INCLUDE
#define PLAYERPOKERSTATUS_H_3E424D10_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerPokerStatus : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 31;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;
        PlayerTableStatus::Enum status;
        bool in_current_hand;

        PlayerPokerStatus() {}

        PlayerPokerStatus(int32_t player, PlayerTableStatus::Enum status, bool in_current_hand) {
            this->player = player;
            this->status = status;
            this->in_current_hand = in_current_hand;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerPokerStatus &playerPokerStatus)
        {
            packetOutputStream << playerPokerStatus.player;
            packetOutputStream << static_cast<uint8_t>(playerPokerStatus.status);
            packetOutputStream << playerPokerStatus.in_current_hand;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerPokerStatus &playerPokerStatus)
        {
            packetInputStream >> playerPokerStatus.player;
            {
                uint8_t temp;
                packetInputStream >> temp;
                playerPokerStatus.status = static_cast<PlayerTableStatus::Enum>(temp);
            }
            packetInputStream >> playerPokerStatus.in_current_hand;
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
