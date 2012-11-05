// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef EXTERNALSESSIONINFOPACKET_H_3FB44626_INCLUDE
#define EXTERNALSESSIONINFOPACKET_H_3FB44626_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class ExternalSessionInfoPacket : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 36;

        virtual uint8_t classId() {
            return CLASSID;
        }

        std::string external_table_reference;
        std::string external_table_session_reference;

        ExternalSessionInfoPacket() {}

        ExternalSessionInfoPacket(std::string external_table_reference, std::string external_table_session_reference) {
            this->external_table_reference = external_table_reference;
            this->external_table_session_reference = external_table_session_reference;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const ExternalSessionInfoPacket &externalSessionInfoPacket)
        {
            packetOutputStream << externalSessionInfoPacket.external_table_reference;
            packetOutputStream << externalSessionInfoPacket.external_table_session_reference;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, ExternalSessionInfoPacket &externalSessionInfoPacket)
        {
            packetInputStream >> externalSessionInfoPacket.external_table_reference;
            packetInputStream >> externalSessionInfoPacket.external_table_session_reference;
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
