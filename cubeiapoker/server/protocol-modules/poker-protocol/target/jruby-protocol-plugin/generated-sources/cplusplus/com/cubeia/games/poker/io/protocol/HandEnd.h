// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef HANDEND_H_597FF66F_INCLUDE
#define HANDEND_H_597FF66F_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "BestHand.h"
#include "PotTransfers.h"


namespace com_cubeia_games_poker_io_protocol
{

    class HandEnd : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 15;

        virtual uint8_t classId() {
            return CLASSID;
        }

        std::vector<int32_t> player_id_reveal_order;
        std::vector<BestHand> hands;
        PotTransfers pot_transfers;

        HandEnd() {}

        HandEnd(std::vector<int32_t> player_id_reveal_order, std::vector<BestHand> hands, PotTransfers pot_transfers) {
            this->player_id_reveal_order = player_id_reveal_order;
            this->hands = hands;
            this->pot_transfers = pot_transfers;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const HandEnd &handEnd)
        {
            packetOutputStream << handEnd.player_id_reveal_order;
            packetOutputStream << handEnd.hands;
            packetOutputStream << handEnd.pot_transfers;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, HandEnd &handEnd)
        {
            packetInputStream >> handEnd.player_id_reveal_order;
            packetInputStream >> handEnd.hands;
            packetInputStream >> handEnd.pot_transfers;
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
