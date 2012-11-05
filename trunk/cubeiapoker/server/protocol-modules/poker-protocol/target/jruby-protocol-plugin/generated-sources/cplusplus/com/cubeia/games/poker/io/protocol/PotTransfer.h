// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef POTTRANSFER_H_4FFDB399_INCLUDE
#define POTTRANSFER_H_4FFDB399_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PotTransfer : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 27;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int8_t pot_id;
        int32_t player_id;
        int32_t amount;

        PotTransfer() {}

        PotTransfer(int8_t pot_id, int32_t player_id, int32_t amount) {
            this->pot_id = pot_id;
            this->player_id = player_id;
            this->amount = amount;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PotTransfer &potTransfer)
        {
            packetOutputStream << potTransfer.pot_id;
            packetOutputStream << potTransfer.player_id;
            packetOutputStream << potTransfer.amount;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PotTransfer &potTransfer)
        {
            packetInputStream >> potTransfer.pot_id;
            packetInputStream >> potTransfer.player_id;
            packetInputStream >> potTransfer.amount;
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
