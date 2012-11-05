// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef STOPHANDHISTORY_H_42694F99_INCLUDE
#define STOPHANDHISTORY_H_42694F99_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class StopHandHistory : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 18;

        virtual uint8_t classId() {
            return CLASSID;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const StopHandHistory &stopHandHistory)
        {
            STYX_UNUSED(stopHandHistory)
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, StopHandHistory &stopHandHistory)
        {
            STYX_UNUSED(stopHandHistory)
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
