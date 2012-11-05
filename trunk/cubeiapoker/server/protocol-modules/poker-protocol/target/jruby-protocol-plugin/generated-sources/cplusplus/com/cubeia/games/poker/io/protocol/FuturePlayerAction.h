// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef FUTUREPLAYERACTION_H_73012205_INCLUDE
#define FUTUREPLAYERACTION_H_73012205_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class FuturePlayerAction : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 3;

        virtual uint8_t classId() {
            return CLASSID;
        }

        ActionType::Enum action;

        FuturePlayerAction() {}

        FuturePlayerAction(ActionType::Enum action) {
            this->action = action;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const FuturePlayerAction &futurePlayerAction)
        {
            packetOutputStream << static_cast<uint8_t>(futurePlayerAction.action);
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, FuturePlayerAction &futurePlayerAction)
        {
            {
                uint8_t temp;
                packetInputStream >> temp;
                futurePlayerAction.action = static_cast<ActionType::Enum>(temp);
            }
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
