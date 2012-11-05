// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef RAKEINFO_H_4DB3AECC_INCLUDE
#define RAKEINFO_H_4DB3AECC_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class RakeInfo : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 30;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t total_pot;
        int32_t total_rake;

        RakeInfo() {}

        RakeInfo(int32_t total_pot, int32_t total_rake) {
            this->total_pot = total_pot;
            this->total_rake = total_rake;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const RakeInfo &rakeInfo)
        {
            packetOutputStream << rakeInfo.total_pot;
            packetOutputStream << rakeInfo.total_rake;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, RakeInfo &rakeInfo)
        {
            packetInputStream >> rakeInfo.total_pot;
            packetInputStream >> rakeInfo.total_rake;
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
