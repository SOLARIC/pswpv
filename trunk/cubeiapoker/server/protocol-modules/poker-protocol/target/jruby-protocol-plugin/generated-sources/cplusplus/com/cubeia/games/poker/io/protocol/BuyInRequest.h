// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef BUYINREQUEST_H_3342740A_INCLUDE
#define BUYINREQUEST_H_3342740A_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class BuyInRequest : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 24;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t amount;
        bool sit_in_if_successful;

        BuyInRequest() {}

        BuyInRequest(int32_t amount, bool sit_in_if_successful) {
            this->amount = amount;
            this->sit_in_if_successful = sit_in_if_successful;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const BuyInRequest &buyInRequest)
        {
            packetOutputStream << buyInRequest.amount;
            packetOutputStream << buyInRequest.sit_in_if_successful;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, BuyInRequest &buyInRequest)
        {
            packetInputStream >> buyInRequest.amount;
            packetInputStream >> buyInRequest.sit_in_if_successful;
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
