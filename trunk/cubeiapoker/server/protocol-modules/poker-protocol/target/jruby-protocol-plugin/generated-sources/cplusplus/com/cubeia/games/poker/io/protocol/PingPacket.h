// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PINGPACKET_H_91AEA4D_INCLUDE
#define PINGPACKET_H_91AEA4D_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PingPacket : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 39;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t identifier;

        PingPacket() {}

        PingPacket(int32_t identifier) {
            this->identifier = identifier;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PingPacket &pingPacket)
        {
            packetOutputStream << pingPacket.identifier;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PingPacket &pingPacket)
        {
            packetInputStream >> pingPacket.identifier;
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
