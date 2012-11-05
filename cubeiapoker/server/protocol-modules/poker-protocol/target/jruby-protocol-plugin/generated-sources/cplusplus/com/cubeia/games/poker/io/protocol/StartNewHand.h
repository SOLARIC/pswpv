// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef STARTNEWHAND_H_2FA55A08_INCLUDE
#define STARTNEWHAND_H_2FA55A08_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class StartNewHand : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 10;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t dealerSeatId;
        std::string handId;

        StartNewHand() {}

        StartNewHand(int32_t dealerSeatId, std::string handId) {
            this->dealerSeatId = dealerSeatId;
            this->handId = handId;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const StartNewHand &startNewHand)
        {
            packetOutputStream << startNewHand.dealerSeatId;
            packetOutputStream << startNewHand.handId;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, StartNewHand &startNewHand)
        {
            packetInputStream >> startNewHand.dealerSeatId;
            packetInputStream >> startNewHand.handId;
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
