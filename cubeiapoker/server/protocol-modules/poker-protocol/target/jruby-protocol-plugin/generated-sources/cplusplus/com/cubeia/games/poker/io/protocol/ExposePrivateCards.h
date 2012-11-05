// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef EXPOSEPRIVATECARDS_H_5A5BAA42_INCLUDE
#define EXPOSEPRIVATECARDS_H_5A5BAA42_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "CardToDeal.h"


namespace com_cubeia_games_poker_io_protocol
{

    class ExposePrivateCards : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 14;

        virtual uint8_t classId() {
            return CLASSID;
        }

        std::vector<CardToDeal> cards;

        ExposePrivateCards() {}

        ExposePrivateCards(std::vector<CardToDeal> cards) {
            this->cards = cards;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const ExposePrivateCards &exposePrivateCards)
        {
            packetOutputStream << exposePrivateCards.cards;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, ExposePrivateCards &exposePrivateCards)
        {
            packetInputStream >> exposePrivateCards.cards;
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
