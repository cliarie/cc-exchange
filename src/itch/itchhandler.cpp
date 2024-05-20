#include "itch/itchhandler.h"

bool ITCHHandler::handle(void *buffer, size_t length)
{
    uint8_t *data = static_cast<uint8_t *>(buffer);
    size_t offset = 0;

    while (offset < length)
    {
        // handle message length: if no message length, read it
        if (this->length == 0)
        {
            // if
            if ((this->buffer.empty()) && length - offset <= 2 || this->buffer.size() == 1)
            {
                this->buffer.push_back(data[offset++]);
                this->length += length - offset;
                return true;
            }

            this->length = (data[offset] << 8) | data[offset + 1];
            offset += 2;
        }

        // read message
        if (length - offset < this->length)
        {
            this->buffer.insert(this->buffer.end(), data + offset, data + length);
            this->length += length - offset;
            return true;
        }

        if (!handle_message(data + offset, this->length))
            return false;

        offset += this->length;
        this->length = 0;
    }
}

bool ITCHHandler::handle_message(void *buffer, size_t length)
{
    if (length < 1)
        return false;

    uint8_t *data = static_cast<uint8_t *>(buffer);
    char message_type = *data;

    switch (message_type)
    {
    case 'S':
        return handle_system_event_message(data, length);
    case 'R':
        return handle_stock_directory_message(data, length);
    case 'H':
        return handle_stock_trading_action_message(data, length);
    case 'Y':
        return handle_reg_sho_message(data, length);
    case 'L':
        return handle_market_participant_position_message(data, length);
    case 'V':
        return handle_mwcb_decline_message(data, length);
    case 'W':
        return handle_mwcb_status_message(data, length);
    case 'K':
        return handle_ipo_quoting_message(data, length);
    case 'J':
        return handle_luld_message(data, length);
    case 'A':
        return handle_add_order_message(data, length);
    case 'F':
        return handle_add_order_mpid_attribution_message(data, length);
    case 'E':
        return handle_order_executed_message(data, length);
    case 'C':
        return handle_order_executed_with_price_message(data, length);
    case 'X':
        return handle_order_cancel_message(data, length);
    case 'D':
        return handle_order_delete_message(data, length);
    case 'U':
        return handle_order_replace_message(data, length);
    case 'P':
        return handle_trade_message(data, length);
    case 'Q':
        return handle_cross_trade_message(data, length);
    case 'B':
        return handle_broken_trade_message(data, length);
    case 'I':
        return handle_noii_message(data, length);
    default:
        return handle_unknown_message(data, length);
    }
}

bool ITCHHandler::handle_system_event_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_stock_directory_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_stock_trading_action_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_reg_sho_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_market_participant_position_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_mwcb_decline_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_mwcb_status_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_ipo_quoting_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_luld_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_add_order_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_add_order_mpid_attribution_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_order_executed_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_order_executed_with_price_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_order_cancel_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_order_delete_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_order_replace_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_trade_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_cross_trade_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_broken_trade_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_noii_message(void *data, size_t length)
{
}

bool ITCHHandler::handle_unknown_message(void *data, size_t length)
{
}

void ITCHHandler::reset()
{
    length = 0;
    buffer.clear();
}