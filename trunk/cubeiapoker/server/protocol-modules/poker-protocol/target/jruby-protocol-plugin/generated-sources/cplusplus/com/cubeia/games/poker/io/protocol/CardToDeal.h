// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef CARDTODEAL_H_613B90A3_INCLUDE
#define CARDTODEAL_H_613B90A3_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "GameCard.h"


namespace com_cubeia_games_poker_io_protocol
{

    class CardToDeal : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 7;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;
        GameCard card;

        CardToDeal() {}

        CardToDeal(int32_t player, GameCard card) {
            this->player = player;
            this->card = card;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const CardToDeal &cardToDeal)
        {
            packetOutputStream << cardToDeal.player;
            packetOutputStream << cardToDeal.card;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, CardToDeal &cardToDeal)
        {
            packetInputStream >> cardToDeal.player;
            packetInputStream >> cardToDeal.card;
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
