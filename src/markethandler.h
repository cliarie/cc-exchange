#pragma once

#include <vector>

class MarketHandler
{
public:
    MarketHandler() = default;
    MarketHandler(const MarketHandler &) = default;
    MarketHandler(MarketHandler &&) noexcept = default;
    ~MarketHandler();

private:
    std::vector<OrderBook> order_books;
    std::vector<Symbol> symbols;
    std::vector<Order> orders;
}