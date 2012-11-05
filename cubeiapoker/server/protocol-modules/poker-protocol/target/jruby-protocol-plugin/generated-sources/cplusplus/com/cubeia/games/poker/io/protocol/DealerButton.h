// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef DEALERBUTTON_H_7A3ED780_INCLUDE
#define DEALERBUTTON_H_7A3ED780_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class DealerButton : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 11;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int8_t seat;

        DealerButton() {}

        DealerButton(int8_t seat) {
            this->seat = seat;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const DealerButton &dealerButton)
        {
            packetOutputStream << dealerButton.seat;
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, DealerButton &dealerButton)
        {
            packetInputStream >> dealerButton.seat;
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
