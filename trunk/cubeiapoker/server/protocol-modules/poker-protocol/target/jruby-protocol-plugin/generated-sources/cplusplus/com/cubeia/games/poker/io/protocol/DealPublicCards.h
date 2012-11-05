// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef DEALPUBLICCARDS_H_6FA19BAE_INCLUDE
#define DEALPUBLICCARDS_H_6FA19BAE_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "GameCard.h"


namespace com_cubeia_games_poker_io_protocol
{

    class DealPublicCards : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 12;

        virtual uint8_t classId() {
            return CLASSID;
        }

        std::vector<GameCard> cards;

        DealPublicCards() {}

        DealPublicCards(std::vector<GameCard> cards) {
            this->cards = cards;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const DealPublicCards &dealPublicCards)
        {
            packetOutputStream << dealPublicCards.cards;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, DealPublicCards &dealPublicCards)
        {
            packetInputStream >> dealPublicCards.cards;
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
