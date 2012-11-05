// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef TOURNAMENTOUT_H_7FA89FF2_INCLUDE
#define TOURNAMENTOUT_H_7FA89FF2_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class TournamentOut : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 20;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t player;
        int32_t position;

        TournamentOut() {}

        TournamentOut(int32_t player, int32_t position) {
            this->player = player;
            this->position = position;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const TournamentOut &tournamentOut)
        {
            packetOutputStream << tournamentOut.player;
            packetOutputStream << tournamentOut.position;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, TournamentOut &tournamentOut)
        {
            packetInputStream >> tournamentOut.player;
            packetInputStream >> tournamentOut.position;
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
