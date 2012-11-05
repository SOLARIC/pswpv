// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERSTATE_H_78F678D7_INCLUDE
#define PLAYERSTATE_H_78F678D7_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "GameCard.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerState : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 6;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;
        std::vector<GameCard> cards;
        int32_t balance;

        PlayerState() {}

        PlayerState(int32_t player, std::vector<GameCard> cards, int32_t balance) {
            this->player = player;
            this->cards = cards;
            this->balance = balance;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerState &playerState)
        {
            packetOutputStream << playerState.player;
            packetOutputStream << playerState.cards;
            packetOutputStream << playerState.balance;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerState &playerState)
        {
            packetInputStream >> playerState.player;
            packetInputStream >> playerState.cards;
            packetInputStream >> playerState.balance;
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
