#pragma once
#include "types.h"

struct Symbol
{
    SymbolId id;
    char name[8];
    Symbol(SymbolId id, const char name[8]) : id{id}
    {
        for (size_t i = 0; i < 8; i++)
        {
            this->name[i] = name[i];
        }
    }
    Symbol(const Symbol &) = default;
    Symbol(Symbol &&) noexcept = default;
    ~Symbol() = default;

    Symbol &operator=(const Symbol &) = default;
    Symbol &operator=(Symbol &&) noexcept = default;

    friend bool operator==(const Symbol &lhs, const Symbol &rhs) noexcept
    {
        return lhs.id == rhs.id;
    }

    friend bool operator!=(const Symbol &lhs, const Symbol &rhs) noexcept
    {
        return !(lhs.id == rhs.id);
    }

    friend bool operator<(const Symbol &lhs, const Symbol &rhs) noexcept
    {
        return lhs.id < rhs.id;
    }

    friend bool operator>(const Symbol &lhs, const Symbol &rhs) noexcept
    {
        return lhs.id > rhs.id;
    }

    friend bool operator<=(const Symbol &lhs, const Symbol &rhs) noexcept
    {
        return lhs.id <= rhs.id;
    }
    friend bool operator>=(const Symbol &lhs, const Symbol &rhs) noexcept
    {
        return lhs.id >= rhs.id;
    }
};