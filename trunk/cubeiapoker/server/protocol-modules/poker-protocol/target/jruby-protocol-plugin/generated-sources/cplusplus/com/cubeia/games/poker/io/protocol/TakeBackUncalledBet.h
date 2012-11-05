// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef TAKEBACKUNCALLEDBET_H_506F592B_INCLUDE
#define TAKEBACKUNCALLEDBET_H_506F592B_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class TakeBackUncalledBet : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 29;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player_id;
        int32_t amount;

        TakeBackUncalledBet() {}

        TakeBackUncalledBet(int32_t player_id, int32_t amount) {
            this->player_id = player_id;
            this->amount = amount;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const TakeBackUncalledBet &takeBackUncalledBet)
        {
            packetOutputStream << takeBackUncalledBet.player_id;
            packetOutputStream << takeBackUncalledBet.amount;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, TakeBackUncalledBet &takeBackUncalledBet)
        {
            packetInputStream >> takeBackUncalledBet.player_id;
            packetInputStream >> takeBackUncalledBet.amount;
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
