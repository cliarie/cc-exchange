#pragma once

#include "order.h"

enum struct LevelType : uint8_t
{
    BID,
    ASK
};

struct Level
{
    Price price;
    Quantity quantity;
    LevelType type;

    Level(Price price, Quantity quantity, LevelType type) noexcept : price{price}, quantity{quantity}, type{type} {};
    Level(const Level &) noexcept = default;
    Level(Level &&) noexcept = default;
    ~Level() noexcept = default;

    Level &operator=(const Level &) noexcept = default;
    Level &operator=(Level &&) noexcept = default;

    friend bool operator==(const Level &lhs, const Level &rhs) noexcept
    {
        return lhs.price == rhs.price;
    }

    friend bool operator!=(const Level &lhs, const Level &rhs) noexcept
    {
        return !(lhs.price == rhs.price);
    }

    friend bool operator<(const Level &lhs, const Level &rhs) noexcept
    {
        return lhs.price < rhs.price;
    }

    friend bool operator>(const Level &lhs, const Level &rhs) noexcept
    {
        return lhs.price > rhs.price;
    }

    friend bool operator<=(const Level &lhs, const Level &rhs) noexcept
    {
        return lhs.price <= rhs.price;
    }
    friend bool operator>=(const Level &lhs, const Level &rhs) noexcept
    {
        return lhs.price >= rhs.price;
    }

    bool is_bid() const noexcept
    {
        return type == LevelType::BID;
    }

    bool is_ask() const noexcept
    {
        return type == LevelType::ASK;
    }
};