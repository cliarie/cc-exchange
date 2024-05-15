#include "order.h"
#include "types.h"
#include "level.h"

struct MessageHeader
{
    uint32_t messageLength;
};

struct NewOrderMessage : public MessageHeader
{
    OrderId orderId;
    SymbolId symbolId;
    Price price;
    Quantity quantity;
    OrderConditions conditions;
};

struct __attribute__((packed)) OrderBookMessage : public MessageHeader
{
    SymbolId symbolId;
    uint32_t numLevels;
    Level levels[0];
};