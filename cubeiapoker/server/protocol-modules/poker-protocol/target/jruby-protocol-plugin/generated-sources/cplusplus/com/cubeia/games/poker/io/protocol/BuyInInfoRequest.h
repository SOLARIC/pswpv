// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef BUYININFOREQUEST_H_4A8770E5_INCLUDE
#define BUYININFOREQUEST_H_4A8770E5_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class BuyInInfoRequest : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 22;

        virtual uint8_t classId() {
            return CLASSID;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const BuyInInfoRequest &buyInInfoRequest)
        {
            STYX_UNUSED(buyInInfoRequest)
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, BuyInInfoRequest &buyInInfoRequest)
        {
            STYX_UNUSED(buyInInfoRequest)
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
