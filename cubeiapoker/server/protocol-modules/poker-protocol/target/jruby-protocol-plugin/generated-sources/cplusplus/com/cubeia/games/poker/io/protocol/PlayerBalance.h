// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef PLAYERBALANCE_H_81D290F_INCLUDE
#define PLAYERBALANCE_H_81D290F_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PlayerBalance : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 21;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t balance;
        int32_t pendingBalance;
        int32_t player;
        int32_t players_contribution_to_pot;

        PlayerBalance() {}

        PlayerBalance(int32_t balance, int32_t pendingBalance, int32_t player, int32_t players_contribution_to_pot) {
            this->balance = balance;
            this->pendingBalance = pendingBalance;
            this->player = player;
            this->players_contribution_to_pot = players_contribution_to_pot;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PlayerBalance &playerBalance)
        {
            packetOutputStream << playerBalance.balance;
            packetOutputStream << playerBalance.pendingBalance;
            packetOutputStream << playerBalance.player;
            packetOutputStream << playerBalance.players_contribution_to_pot;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PlayerBalance &playerBalance)
        {
            packetInputStream >> playerBalance.balance;
            packetInputStream >> playerBalance.pendingBalance;
            packetInputStream >> playerBalance.player;
            packetInputStream >> playerBalance.players_contribution_to_pot;
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
