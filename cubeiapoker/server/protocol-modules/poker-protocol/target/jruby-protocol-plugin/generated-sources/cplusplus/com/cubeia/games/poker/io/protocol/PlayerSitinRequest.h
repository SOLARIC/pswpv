// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERSITINREQUEST_H_5E4C616E_INCLUDE
#define PLAYERSITINREQUEST_H_5E4C616E_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerSitinRequest : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 33;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;

        PlayerSitinRequest() {}

        PlayerSitinRequest(int32_t player) {
            this->player = player;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerSitinRequest &playerSitinRequest)
        {
            packetOutputStream << playerSitinRequest.player;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerSitinRequest &playerSitinRequest)
        {
            packetInputStream >> playerSitinRequest.player;
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
