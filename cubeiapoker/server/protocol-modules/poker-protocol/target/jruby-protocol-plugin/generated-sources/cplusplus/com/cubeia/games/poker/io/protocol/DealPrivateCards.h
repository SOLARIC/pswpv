// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef DEALPRIVATECARDS_H_680DADB5_INCLUDE
#define DEALPRIVATECARDS_H_680DADB5_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "CardToDeal.h"


namespace com_cubeia_games_poker_io_protocol
{

    class DealPrivateCards : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 13;

        virtual uint8_t classId() {
            return CLASSID;
        }

        std::vector<CardToDeal> cards;

        DealPrivateCards() {}

        DealPrivateCards(std::vector<CardToDeal> cards) {
            this->cards = cards;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const DealPrivateCards &dealPrivateCards)
        {
            packetOutputStream << dealPrivateCards.cards;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, DealPrivateCards &dealPrivateCards)
        {
            packetInputStream >> dealPrivateCards.cards;
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
