// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef ERRORPACKET_H_35F8DDCD_INCLUDE
#define ERRORPACKET_H_35F8DDCD_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class ErrorPacket : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 2;

        virtual uint8_t classId() {
            return CLASSID;
        }

        ErrorCode::Enum code;
        std::string reference_id;

        ErrorPacket() {}

        ErrorPacket(ErrorCode::Enum code, std::string reference_id) {
            this->code = code;
            this->reference_id = reference_id;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const ErrorPacket &errorPacket)
        {
            packetOutputStream << static_cast<uint8_t>(errorPacket.code);
            packetOutputStream << errorPacket.reference_id;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, ErrorPacket &errorPacket)
        {
            {
                uint8_t temp;
                packetInputStream >> temp;
                errorPacket.code = static_cast<ErrorCode::Enum>(temp);
            }
            packetInputStream >> errorPacket.reference_id;
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
