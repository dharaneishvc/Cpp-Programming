#include "OrderBook.h"
#include <map>
#include <algorithm>

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::map<std::string, bool> prodMap;

    for (const OrderBookEntry &e : orders)
    {
        prodMap[e.product] = true;
    }

    std::vector<std::string> products;
    for (const auto &e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> filteredOrders;

    for (const auto &order : orders)
    {
        if (order.type == type && order.product == product && order.timestamp == timestamp)
        {
            filteredOrders.push_back(order);
        }
    }

    return filteredOrders;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders)
{
    double max = 0.0;

    for (const auto &order : orders)
    {
        if (order.price > max)
        {
            max = order.price;
        }
    }

    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders)
{
    double min = orders.empty() ? 0.0 : orders[0].price;

    for (const auto &order : orders)
    {
        if (order.price < min)
        {
            min = order.price;
        }
    }

    return min;
}

void OrderBook::insertOrder(OrderBookEntry &order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::string OrderBook::getEarliestTime()
{
    if (orders.empty())
    {
        return ""; // Handle edge case where no orders exist
    }

    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(const std::string &timestamp)
{
    std::string next_timestamp = "";
    for (const auto &e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }

    if (next_timestamp == "")
    {
        next_timestamp = getEarliestTime(); // Wrap around to the earliest time
    }

    return next_timestamp;
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp); // Fixed here
    std::vector<OrderBookEntry> sales;

    // Sort asks lowest first
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);

    // Sort bids highest first
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    // Matching algorithm
    for (auto &ask : asks)
    {
        for (auto &bid : bids)
        {
            if (bid.price >= ask.price && bid.amount > 0 && ask.amount > 0)
            { // we have a match
                OrderBookEntry sale{timestamp, product, OrderBookType::unknown, ask.price, 0};

                if (bid.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.type = OrderBookType::bidsale;
                }
                else if (ask.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.type = OrderBookType::asksale;
                }

                if (bid.amount == ask.amount)
                { // bid completely clears ask
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0; // mark bid as fully processed
                    ask.amount = 0; // mark ask as fully processed
                    break;          // go to next ask
                }
                else if (bid.amount > ask.amount)
                { // ask is completely gone, slice the bid
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount -= ask.amount; // reduce bid amount
                    ask.amount = 0;           // mark ask as fully processed
                    break;                    // go to next ask
                }
                else
                { // bid.amount < ask.amount, bid is completely gone, slice the ask
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount -= bid.amount; // reduce ask amount
                    bid.amount = 0;           // mark bid as fully processed
                    // continue to check against next bid
                }
            }
        }
    }

    return sales;
}
