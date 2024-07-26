#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown, // Added for handling unknown types
    asksale,
    bidsale,
};

class OrderBookEntry
{
public:
    std::string timestamp;
    std::string product;
    OrderBookType type;
    double price;
    double amount;
    std::string username;

    OrderBookEntry(std::string _timestamp, std::string _product,
                   OrderBookType _type, double _price, double _amount,
                   std::string username = "dataset");

    static OrderBookType stringToOrderBookType(const std::string &s);
    static bool compareByTimestamp(const OrderBookEntry &e1, const OrderBookEntry &e2);

    static bool compareByPriceAsc(const OrderBookEntry &e1, const OrderBookEntry &e2);
    static bool compareByPriceDesc(const OrderBookEntry &e1, const OrderBookEntry &e2);
};
