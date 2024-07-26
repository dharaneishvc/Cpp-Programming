#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(std::string _timestamp, std::string _product, OrderBookType _type, double _price, double _amount, std::string _username)
    : timestamp(_timestamp), product(_product), type(_type), price(_price), amount(_amount), username(_username)
{
}

OrderBookType OrderBookEntry::stringToOrderBookType(const std::string &s)
{
    if (s == "ask")
    {
        return OrderBookType::ask;
    }
    else if (s == "bid")
    {
        return OrderBookType::bid;
    }
    else
    {
        return OrderBookType::unknown;
    }
}

bool OrderBookEntry::compareByTimestamp(const OrderBookEntry &e1, const OrderBookEntry &e2)
{
    return e1.timestamp < e2.timestamp;
}

bool OrderBookEntry::compareByPriceAsc(const OrderBookEntry &e1, const OrderBookEntry &e2)
{
    return e1.price < e2.price;
}

bool OrderBookEntry::compareByPriceDesc(const OrderBookEntry &e1, const OrderBookEntry &e2)
{
    return e1.price > e2.price;
}
