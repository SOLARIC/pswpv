// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERACTION_H_4EF1FD9_INCLUDE
#define PLAYERACTION_H_4EF1FD9_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerAction : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 1;

        virtual uint8_t classId() {
            return CLASSID;
        }

        ActionType::Enum type;
        int32_t min_amount;
        int32_t max_amount;

        PlayerAction() {}

        PlayerAction(ActionType::Enum type, int32_t min_amount, int32_t max_amount) {
            this->type = type;
            this->min_amount = min_amount;
            this->max_amount = max_amount;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerAction &playerAction)
        {
            packetOutputStream << static_cast<uint8_t>(playerAction.type);
            packetOutputStream << playerAction.min_amount;
            packetOutputStream << playerAction.max_amount;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerAction &playerAction)
        {
            {
                uint8_t temp;
                packetInputStream >> temp;
                playerAction.type = static_cast<ActionType::Enum>(temp);
            }
            packetInputStream >> playerAction.min_amount;
            packetInputStream >> playerAction.max_amount;
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
