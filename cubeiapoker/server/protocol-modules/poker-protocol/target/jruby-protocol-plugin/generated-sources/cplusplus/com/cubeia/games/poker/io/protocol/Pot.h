// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef POT_H_6363C087_INCLUDE
#define POT_H_6363C087_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class Pot : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 26;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int8_t id;
        PotType::Enum type;
        int32_t amount;

        Pot() {}

        Pot(int8_t id, PotType::Enum type, int32_t amount) {
            this->id = id;
            this->type = type;
            this->amount = amount;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const Pot &pot)
        {
            packetOutputStream << pot.id;
            packetOutputStream << static_cast<uint8_t>(pot.type);
            packetOutputStream << pot.amount;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, Pot &pot)
        {
            packetInputStream >> pot.id;
            {
                uint8_t temp;
                packetInputStream >> temp;
                pot.type = static_cast<PotType::Enum>(temp);
            }
            packetInputStream >> pot.amount;
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
