// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PERFORMACTION_H_6F01D404_INCLUDE
#define PERFORMACTION_H_6F01D404_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "PlayerAction.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PerformAction : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 19;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t seq;
        int32_t player;
        PlayerAction action;
        int32_t bet_amount;
        int32_t raise_amount;
        int32_t stack_amount;
        bool timeout;

        PerformAction() {}

        PerformAction(int32_t seq, int32_t player, PlayerAction action, int32_t bet_amount, int32_t raise_amount, int32_t stack_amount, bool timeout) {
            this->seq = seq;
            this->player = player;
            this->action = action;
            this->bet_amount = bet_amount;
            this->raise_amount = raise_amount;
            this->stack_amount = stack_amount;
            this->timeout = timeout;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PerformAction &performAction)
        {
            packetOutputStream << performAction.seq;
            packetOutputStream << performAction.player;
            packetOutputStream << performAction.action;
            packetOutputStream << performAction.bet_amount;
            packetOutputStream << performAction.raise_amount;
            packetOutputStream << performAction.stack_amount;
            packetOutputStream << performAction.timeout;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PerformAction &performAction)
        {
            packetInputStream >> performAction.seq;
            packetInputStream >> performAction.player;
            packetInputStream >> performAction.action;
            packetInputStream >> performAction.bet_amount;
            packetInputStream >> performAction.raise_amount;
            packetInputStream >> performAction.stack_amount;
            packetInputStream >> performAction.timeout;
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
