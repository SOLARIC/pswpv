// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef GAMECARD_H_76AC77AC_INCLUDE
#define GAMECARD_H_76AC77AC_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class GameCard : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 4;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t card_id;
        Suit::Enum suit;
        Rank::Enum rank;

        GameCard() {}

        GameCard(int32_t card_id, Suit::Enum suit, Rank::Enum rank) {
            this->card_id = card_id;
            this->suit = suit;
            this->rank = rank;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const GameCard &gameCard)
        {
            packetOutputStream << gameCard.card_id;
            packetOutputStream << static_cast<uint8_t>(gameCard.suit);
            packetOutputStream << static_cast<uint8_t>(gameCard.rank);
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, GameCard &gameCard)
        {
            packetInputStream >> gameCard.card_id;
            {
                uint8_t temp;
                packetInputStream >> temp;
                gameCard.suit = static_cast<Suit::Enum>(temp);
            }
            {
                uint8_t temp;
                packetInputStream >> temp;
                gameCard.rank = static_cast<Rank::Enum>(temp);
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
