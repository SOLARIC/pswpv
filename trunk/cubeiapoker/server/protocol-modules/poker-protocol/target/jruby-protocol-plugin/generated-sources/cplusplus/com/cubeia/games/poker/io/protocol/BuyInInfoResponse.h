// I AM AUTO-GENERATED, DON'T CHECK ME INTO SUBVERSION (or else...)

#ifndef BUYININFORESPONSE_H_65989BEE_INCLUDE
#define BUYININFORESPONSE_H_65989BEE_INCLUDE

#include "styx_support.h"
#include "PacketInputStream.h"
#include "PacketOutputStream.h"
#include "ProtocolEnums.h"
#include "ProtocolObject.h"


namespace com_cubeia_games_poker_io_protocol
{

    class BuyInInfoResponse : public styx::ProtocolObject {

    public:

        static const uint8_t CLASSID = 23;

        virtual uint8_t classId() {
            return CLASSID;
        }

        int32_t max_amount;
        int32_t min_amount;
        int32_t balance_in_wallet;
        int32_t balance_on_table;
        bool mandatory_buyin;
        BuyInInfoResultCode::Enum result_code;

        BuyInInfoResponse() {}

        BuyInInfoResponse(int32_t max_amount, int32_t min_amount, int32_t balance_in_wallet, int32_t balance_on_table, bool mandatory_buyin, BuyInInfoResultCode::Enum result_code) {
            this->max_amount = max_amount;
            this->min_amount = min_amount;
            this->balance_in_wallet = balance_in_wallet;
            this->balance_on_table = balance_on_table;
            this->mandatory_buyin = mandatory_buyin;
            this->result_code = result_code;
        }

        friend styx::PacketOutputStream& operator<<(styx::PacketOutputStream &packetOutputStream, const BuyInInfoResponse &buyInInfoResponse)
        {
            packetOutputStream << buyInInfoResponse.max_amount;
            packetOutputStream << buyInInfoResponse.min_amount;
            packetOutputStream << buyInInfoResponse.balance_in_wallet;
            packetOutputStream << buyInInfoResponse.balance_on_table;
            packetOutputStream << buyInInfoResponse.mandatory_buyin;
            packetOutputStream << static_cast<uint8_t>(buyInInfoResponse.result_code);
            packetOutputStream.finish();
            return packetOutputStream;
        }

        friend styx::PacketInputStream & operator>>(styx::PacketInputStream &packetInputStream, BuyInInfoResponse &buyInInfoResponse)
        {
            packetInputStream >> buyInInfoResponse.max_amount;
            packetInputStream >> buyInInfoResponse.min_amount;
            packetInputStream >> buyInInfoResponse.balance_in_wallet;
            packetInputStream >> buyInInfoResponse.balance_on_table;
            packetInputStream >> buyInInfoResponse.mandatory_buyin;
            {
                uint8_t temp;
                packetInputStream >> temp;
                buyInInfoResponse.resultCode = static_cast<BuyInInfoResultCode::Enum>(temp);
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
