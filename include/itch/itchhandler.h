#pragma once
#include <cstdint>
#include <cstring>
#include <vector>

/*
Nasdaq ITCH Protocol
*/

struct SystemEventMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char event_code;
};

struct StockDirectoryMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char stock[8];
    char market_category;
    char financial_status_indicator;
    std::uint32_t round_lot_size;
    char round_lots_only;
    char issue_classification;
    char issue_sub_type[2];
    char authenticity;
    char short_sale_threshold_indicator;
    char ipo_flag;
    std::uint64_t luld_reference_price_tier;
    char etp_flag;
    std::uint32_t etp_leverage_factor;
    char inverse_indicator;
};

struct StockTradingActionMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char stock[8];
    char trading_state;
    char reserved;
    char reason[4];
};

struct RegSHOMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char stock[8];
    char reg_sho_action;
};

struct MarketParticipantPositionMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char mpid[4];
    char stock[8];
    char primary_market_maker;
    char market_maker_mode;
    char market_participant_state;
};

struct MWCBDeclineMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t level_1;
    std::uint64_t level_2;
    std::uint64_t level_3;
};

struct MWCBStatusMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char breach;
};

struct IPOQuotingMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char stock[8];
    std::uint32_t ipo_release_time;
    char ipo_quotation_release_qualifier;
    std::uint32_t ipo_price;
};

struct LULD
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char stock[8];
    std::uint32_t auction_collar_reference_price;
    std::uint32_t upper_auction_collar_price;
    std::uint32_t lower_auction_collar_price;
    std::uint32_t auction_collar_extension;
};

struct AddOrderMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
    char buy_sell_indicator;
    std::uint32_t shares;
    char stock[8];
    std::uint64_t price;
};

struct AddOrderMPIDAttributionMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
    char buy_sell_indicator;
    std::uint32_t shares;
    char stock[8];
    std::uint64_t price;
    char attribution[4];
};

struct OrderExecutedMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
    std::uint32_t executed_shares;
    std::uint64_t match_number;
};

struct OrderExecutedWithPriceMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
    std::uint32_t executed_shares;
    std::uint64_t match_number;
    char printable;
    std::uint64_t price;
};

struct OrderCancelMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
    std::uint32_t canceled_shares;
};

struct OrderDeleteMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
};

struct OrderReplaceMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t original_order_reference_number;
    std::uint64_t new_order_reference_number;
    std::uint32_t shares;
    std::uint64_t price;
};

struct TradeMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t order_reference_number;
    char buy_sell_indicator;
    std::uint32_t shares;
    char stock[8];
    std::uint64_t price;
    std::uint64_t match_number;
};

struct CrossTradeMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t shares;
    char stock[8];
    std::uint64_t cross_price;
    std::uint64_t match_number;
    char cross_type;
};

struct BrokenTradeMessage
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    std::uint64_t match_number;
};

struct NOII
{
    char message_type;
    std::uint16_t stock_locate;
    std::uint16_t tracking_number;
    std::uint64_t timestamp;
    char paired_shares[9];
    char imbalance_shares[9];
    char imbalance_direction;
    char stock[8];
    std::uint64_t far_price;
    std::uint64_t near_price;
    char current_reference_price;
    char cross_type;
    char price_variation_indicator;
};

struct UnknownMessage
{
    char message_type;
};

/*
Parse ITCH messages
*/
class ITCHHandler
{
public:
    ITCHHandler() { reset(); };
    ITCHHandler(const ITCHHandler &) = delete;
    ITCHHandler(ITCHHandler &&) = delete;
    virtual ~ITCHHandler() = default;

    ITCHHandler &operator=(const ITCHHandler &) = delete;
    ITCHHandler &operator=(ITCHHandler &&) = delete;

    // Process all messages from ITCH buffer
    bool handle(void *buffer, std::size_t length);

    // Process message from ITCH buffer
    bool handle_message(void *buffer, std::size_t length);

    // Reset ITCH Handler
    void reset();

private:
    size_t length;
    std::vector<uint8_t> buffer;

    bool handle_system_event_message(void *buffer, std::size_t length);
    bool handle_stock_directory_message(void *buffer, std::size_t length);
    bool handle_stock_trading_action_message(void *buffer, std::size_t length);
    bool handle_reg_sho_message(void *buffer, std::size_t length);
    bool handle_market_participant_position_message(void *buffer, std::size_t length);
    bool handle_mwcb_decline_message(void *buffer, std::size_t length);
    bool handle_mwcb_status_message(void *buffer, std::size_t length);
    bool handle_ipo_quoting_message(void *buffer, std::size_t length);
    bool handle_luld_message(void *buffer, std::size_t length);
    bool handle_add_order_message(void *buffer, std::size_t length);
    bool handle_add_order_mpid_attribution_message(void *buffer, std::size_t length);
    bool handle_order_executed_message(void *buffer, std::size_t length);
    bool handle_order_executed_with_price_message(void *buffer, std::size_t length);
    bool handle_order_cancel_message(void *buffer, std::size_t length);
    bool handle_order_delete_message(void *buffer, std::size_t length);
    bool handle_order_replace_message(void *buffer, std::size_t length);
    bool handle_trade_message(void *buffer, std::size_t length);
    bool handle_cross_trade_message(void *buffer, std::size_t length);
    bool handle_broken_trade_message(void *buffer, std::size_t length);
    bool handle_noii_message(void *buffer, std::size_t length);
    bool handle_unknown_message(void *buffer, std::size_t length);
};