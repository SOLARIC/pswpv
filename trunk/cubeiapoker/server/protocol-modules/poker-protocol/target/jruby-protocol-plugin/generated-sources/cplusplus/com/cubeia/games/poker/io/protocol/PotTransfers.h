// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef POTTRANSFERS_H_2039418E_INCLUDE
#define POTTRANSFERS_H_2039418E_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"
#include "PotTransfer.h"
#include "Pot.h"


namespace com_cubeia_games_poker_io_protocol
{

    class PotTransfers : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 28;

        virtual uint8_t classId() {
            return CLASSID;
        }

        bool fromPlayerToPot;
        std::vector<PotTransfer> transfers;
        std::vector<Pot> pots;

        PotTransfers() {}

        PotTransfers(bool fromPlayerToPot, std::vector<PotTransfer> transfers, std::vector<Pot> pots) {
            this->fromPlayerToPot = fromPlayerToPot;
            this->transfers = transfers;
            this->pots = pots;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const PotTransfers &potTransfers)
        {
            packetOutputStream << potTransfers.fromPlayerToPot;
            packetOutputStream << potTransfers.transfers;
            packetOutputStream << potTransfers.pots;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, PotTransfers &potTransfers)
        {
            packetInputStream >> potTransfers.fromPlayerToPot;
            packetInputStream >> potTransfers.transfers;
            packetInputStream >> potTransfers.pots;
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
