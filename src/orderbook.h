#pragma once

#include "types.h"
#include "order.h"
#include "level.h"

#include <vector>

class OrderBook
{
public:
    OrderBook() = default;
    OrderBook(const OrderBook &) = default;
    OrderBook(OrderBook &&) noexcept = default;
    ~OrderBook();

    void add_order(const Order &order) noexcept;
    void modify_order(const Order &order) noexcept;
    void remove_order(const Order &order) noexcept;
    void match_order(const Order &order) noexcept;

private:
    std::vector<Order> orders;
    std::vector<Level> bids;
    std::vector<Level> asks;
    std::vector<Order> cancelled_orders;
    std::vector<Order> filled_orders;
};