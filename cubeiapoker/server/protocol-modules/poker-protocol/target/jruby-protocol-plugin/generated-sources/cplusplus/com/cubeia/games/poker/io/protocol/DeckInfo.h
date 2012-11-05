// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef DECKINFO_H_3C9995E1_INCLUDE
#define DECKINFO_H_3C9995E1_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class DeckInfo : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 35;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t size;
        Rank::Enum rank_low;

        DeckInfo() {}

        DeckInfo(int32_t size, Rank::Enum rank_low) {
            this->size = size;
            this->rank_low = rank_low;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const DeckInfo &deckInfo)
        {
            packetOutputStream << deckInfo.size;
            packetOutputStream << static_cast<uint8_t>(deckInfo.rank_low);
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, DeckInfo &deckInfo)
        {
            packetInputStream >> deckInfo.size;
            {
                uint8_t temp;
                packetInputStream >> temp;
                deckInfo.rankLow = static_cast<Rank::Enum>(temp);
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
