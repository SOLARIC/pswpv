// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef BUYINRESPONSE_H_6C6D65B7_INCLUDE
#define BUYINRESPONSE_H_6C6D65B7_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class BuyInResponse : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 25;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t balance;
        int32_t pending_balance;
        int32_t amount_brought_in;
        BuyInResultCode::Enum result_code;

        BuyInResponse() {}

        BuyInResponse(int32_t balance, int32_t pending_balance, int32_t amount_brought_in, BuyInResultCode::Enum result_code) {
            this->balance = balance;
            this->pending_balance = pending_balance;
            this->amount_brought_in = amount_brought_in;
            this->result_code = result_code;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const BuyInResponse &buyInResponse)
        {
            packetOutputStream << buyInResponse.balance;
            packetOutputStream << buyInResponse.pending_balance;
            packetOutputStream << buyInResponse.amount_brought_in;
            packetOutputStream << static_cast<uint8_t>(buyInResponse.result_code);
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, BuyInResponse &buyInResponse)
        {
            packetInputStream >> buyInResponse.balance;
            packetInputStream >> buyInResponse.pending_balance;
            packetInputStream >> buyInResponse.amount_brought_in;
            {
                uint8_t temp;
                packetInputStream >> temp;
                buyInResponse.resultCode = static_cast<BuyInResultCode::Enum>(temp);
            }
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
