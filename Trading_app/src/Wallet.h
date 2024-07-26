#pragma once

#include <string>
#include <map>
#include <iostream>
#include "OrderBookEntry.h"

class Wallet
{
public:
    Wallet();

    /** Insert currency into the wallet */
    void insertCurrency(const std::string &type, double amount);

    /** Remove currency from the wallet */
    bool removeCurrency(const std::string &type, double amount);

    /** Check if the wallet contains this much currency or more */
    bool containsCurrency(const std::string &type, double amount) const;

    /** Generate a string representation of the wallet */
    std::string toString() const;

    /** Overload the << operator to print the Wallet */
    friend std::ostream &operator<<(std::ostream &os, const Wallet &wallet);

    /** Checks whether an order sale is possible or not with wallet */
    bool canFulfillOrder(OrderBookEntry order);

    /** Use to process sale */
    void processSale(OrderBookEntry &sale);

private:
    std::map<std::string, double> currencies;
};


