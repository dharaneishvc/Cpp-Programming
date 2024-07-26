#include "Wallet.h"
#include <stdexcept>
#include <sstream>
#include <vector>
#include <string.h>
#include "CSVReader.h"

Wallet::Wallet()
{
}

// Insert currency into the wallet
void Wallet::insertCurrency(const std::string &type, double amount)
{
    if (amount < 0)
    {
        throw std::invalid_argument("Amount must be non-negative.");
    }
    currencies[type] += amount;
}

// Remove currency from the wallet
bool Wallet::removeCurrency(const std::string &type, double amount)
{
    if (amount < 0)
    {
        throw std::invalid_argument("Amount must be non-negative.");
    }

    auto it = currencies.find(type);
    if (it == currencies.end() || it->second < amount)
    {
        // Currency type does not exist or insufficient funds
        return false;
    }

    // Subtract the currency amount
    it->second -= amount;
    if (it->second == 0)
    {
        currencies.erase(it); // Remove the entry if the amount drops to zero
    }
    return true;
}

// Check if the wallet contains at least the specified amount of currency
bool Wallet::containsCurrency(const std::string &type, double amount) const
{
    if (amount < 0)
    {
        throw std::invalid_argument("Amount must be non-negative.");
    }

    auto it = currencies.find(type);
    return it != currencies.end() && it->second >= amount;
}

// Generate a string representation of the wallet
std::string Wallet::toString() const
{
    std::ostringstream oss;
    for (const auto &pair : currencies)
    {
        oss << pair.first << " : " << pair.second << "\n";
    }
    return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Wallet &wallet)
{
    os << wallet.toString();
    return os;
}

bool Wallet::canFulfillOrder(OrderBookEntry entry)
{
    if (entry.amount < 0 || entry.price <= 0)
    {
        throw std::invalid_argument("Amount must be non-negative and price must be positive.");
    }

    // Tokenize currency pair using CSVReader::tokenize
    std::string currencyPair = entry.product;
    std::vector<std::string> tokens = CSVReader::tokenise(currencyPair, '/');

    if (tokens.size() != 2)
    {
        throw std::invalid_argument("Currency pair must be in the format 'C1/C2'.");
    }

    std::string c1 = tokens[0];
    std::string c2 = tokens[1];

    double amount = entry.amount;
    double price = entry.price;
    OrderBookType orderType = entry.type;

    switch (orderType)
    {
    case OrderBookType::ask:
    {
        // For an ask order, check if the wallet contains enough of currency C1
        return containsCurrency(c1, price);
    }
    case OrderBookType::bid:
    {
        // For a bid order, calculate the total amount of currency C2 needed
        double totalAmountNeeded = amount * price;
        return containsCurrency(c2, totalAmountNeeded);
    }
    default:
        throw std::invalid_argument("Invalid order type.");
    }
}

void Wallet::processSale(OrderBookEntry &sale)
{
    std::vector<std::string> currs = CSVReader::tokenise(sale.product, '/');

    if (sale.type == OrderBookType::asksale)
    {
        double outgoingAmount = sale.amount;
        std::string outgoingCurrency = currs[0];
        double incomingAmount = sale.amount * sale.price;
        std::string incomingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
    else if (sale.type == OrderBookType::bidsale)
    {
        double incomingAmount = sale.amount;
        std::string incomingCurrency = currs[0];
        double outgoingAmount = sale.amount * sale.price;
        std::string outgoingCurrency = currs[1];
        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
}
