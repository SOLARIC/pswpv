// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef REQUESTACTION_H_5FD45383_INCLUDE
#define REQUESTACTION_H_5FD45383_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "PlayerAction.h"


namespace com_cubeia_games_poker_io_protocol
{

    class RequestAction : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 8;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t current_pot_size;
        int32_t seq;
        int32_t player;
        std::vector<PlayerAction> allowed_actions;
        int32_t time_to_act;

        RequestAction() {}

        RequestAction(int32_t current_pot_size, int32_t seq, int32_t player, std::vector<PlayerAction> allowed_actions, int32_t time_to_act) {
            this->current_pot_size = current_pot_size;
            this->seq = seq;
            this->player = player;
            this->allowed_actions = allowed_actions;
            this->time_to_act = time_to_act;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const RequestAction &requestAction)
        {
            packetOutputStream << requestAction.current_pot_size;
            packetOutputStream << requestAction.seq;
            packetOutputStream << requestAction.player;
            packetOutputStream << requestAction.allowed_actions;
            packetOutputStream << requestAction.time_to_act;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, RequestAction &requestAction)
        {
            packetInputStream >> requestAction.current_pot_size;
            packetInputStream >> requestAction.seq;
            packetInputStream >> requestAction.player;
            packetInputStream >> requestAction.allowed_actions;
            packetInputStream >> requestAction.time_to_act;
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
