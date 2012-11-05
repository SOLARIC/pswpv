// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef INFORMFUTUREALLOWEDACTIONS_H_9BC61B1_INCLUDE
#define INFORMFUTUREALLOWEDACTIONS_H_9BC61B1_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "FuturePlayerAction.h"


namespace com_cubeia_games_poker_io_protocol
{

    class InformFutureAllowedActions : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 9;

        virtual uint8_t classId() {
            return CLASSID;
        }

        std::vector<FuturePlayerAction> actions;

        InformFutureAllowedActions() {}

        InformFutureAllowedActions(std::vector<FuturePlayerAction> actions) {
            this->actions = actions;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const InformFutureAllowedActions &informFutureAllowedActions)
        {
            packetOutputStream << informFutureAllowedActions.actions;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, InformFutureAllowedActions &informFutureAllowedActions)
        {
            packetInputStream >> informFutureAllowedActions.actions;
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
