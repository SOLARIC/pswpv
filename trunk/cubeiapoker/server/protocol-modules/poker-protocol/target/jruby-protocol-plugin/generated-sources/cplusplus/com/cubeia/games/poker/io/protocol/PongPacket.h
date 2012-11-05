// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PONGPACKET_H_61B68D41_INCLUDE
#define PONGPACKET_H_61B68D41_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PongPacket : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 40;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t identifier;

        PongPacket() {}

        PongPacket(int32_t identifier) {
            this->identifier = identifier;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PongPacket &pongPacket)
        {
            packetOutputStream << pongPacket.identifier;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PongPacket &pongPacket)
        {
            packetInputStream >> pongPacket.identifier;
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
