// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef BESTHAND_H_7A04AC06_INCLUDE
#define BESTHAND_H_7A04AC06_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "GameCard.h"


namespace com_cubeia_games_poker_io_protocol
{

    class BestHand : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 5;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;
        HandType::Enum hand_type;
        std::vector<GameCard> cards;

        BestHand() {}

        BestHand(int32_t player, HandType::Enum hand_type, std::vector<GameCard> cards) {
            this->player = player;
            this->hand_type = hand_type;
            this->cards = cards;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const BestHand &bestHand)
        {
            packetOutputStream << bestHand.player;
            packetOutputStream << static_cast<uint8_t>(bestHand.hand_type);
            packetOutputStream << bestHand.cards;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, BestHand &bestHand)
        {
            packetInputStream >> bestHand.player;
            {
                uint8_t temp;
                packetInputStream >> temp;
                bestHand.handType = static_cast<HandType::Enum>(temp);
            }
            packetInputStream >> bestHand.cards;
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
