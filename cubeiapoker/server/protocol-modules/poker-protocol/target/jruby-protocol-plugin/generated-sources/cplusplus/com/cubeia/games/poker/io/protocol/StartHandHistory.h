// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef STARTHANDHISTORY_H_7722EF06_INCLUDE
#define STARTHANDHISTORY_H_7722EF06_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class StartHandHistory : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 17;

        virtual uint8_t classId() {
            return CLASSID;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const StartHandHistory &startHandHistory)
        {
            STYX_UNUSED(startHandHistory)
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, StartHandHistory &startHandHistory)
        {
            STYX_UNUSED(startHandHistory)
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
