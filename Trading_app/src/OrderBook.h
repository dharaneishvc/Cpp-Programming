#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>

class OrderBook
{
public:
    OrderBook(std::string filename);

    std::vector<std::string> getKnownProducts();
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);
    std::string getEarliestTime();
    std::string getNextTime(const std::string &timestamp);

    void insertOrder(OrderBookEntry &order);

    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    static double getLowPrice(std::vector<OrderBookEntry> &orders);

    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);
    
private :
    std::vector<OrderBookEntry> orders;
};
