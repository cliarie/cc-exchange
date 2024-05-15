#pragma once

#include "types.h"

enum struct OrderSide : uint8_t
{
    BUY,
    SELL
};

enum struct OrderType : uint8_t
{
    LIMIT,
    MARKET
};

enum struct OrderConditions : uint8_t
{
    GTC,
    IOC
};

struct Order
{
    OrderId id;
    SymbolId symbol;
    OrderType type;
    OrderSide side;
    Price price;
    Quantity quantity;
    OrderConditions conditions;

    Order(OrderId id, SymbolId symbol, OrderType type, OrderSide side, Price price, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept : id{id}, symbol{symbol}, type{type}, side{side}, price{price}, quantity{quantity}, conditions{conditions} {};
    Order(const Order &) noexcept = default;
    Order(Order &&) noexcept = default;
    ~Order() noexcept = default;

    Order &operator=(const Order &) noexcept = default;
    Order &operator=(Order &&) noexcept = default;

    bool is_buy() const noexcept
    {
        return side == OrderSide::BUY;
    }

    bool is_sell() const noexcept
    {
        return side == OrderSide::SELL;
    }

    bool is_limit() const noexcept
    {
        return type == OrderType::LIMIT;
    }

    bool is_market() const noexcept
    {
        return type == OrderType::MARKET;
    }

    bool is_gtc() const noexcept
    {
        return conditions == OrderConditions::GTC;
    }

    bool is_ioc() const noexcept
    {
        return conditions == OrderConditions::IOC;
    }

    static Order create_market_order(OrderId id, SymbolId symbol, OrderSide side, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept
    {
        return Order(id, symbol, OrderType::MARKET, side, 0, quantity, conditions);
    }

    static Order create_buy_market_order(OrderId id, SymbolId symbol, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept
    {
        return create_market_order(id, symbol, OrderSide::BUY, quantity, conditions);
    }

    static Order create_sell_market_order(OrderId id, SymbolId symbol, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept
    {
        return create_market_order(id, symbol, OrderSide::SELL, quantity, conditions);
    }

    static Order create_limit_order(OrderId id, SymbolId symbol, OrderSide side, Price price, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept
    {
        return Order(id, symbol, OrderType::LIMIT, side, price, quantity, conditions);
    }

    static Order create_buy_limit_order(OrderId id, SymbolId symbol, Price price, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept
    {
        return create_limit_order(id, symbol, OrderSide::BUY, price, quantity, conditions);
    }

    static Order create_sell_limit_order(OrderId id, SymbolId symbol, Price price, Quantity quantity, OrderConditions conditions = OrderConditions::GTC) noexcept
    {
        return create_limit_order(id, symbol, OrderSide::SELL, price, quantity, conditions);
    }
};
