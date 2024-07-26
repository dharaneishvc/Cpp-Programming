#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"
#include <string>

class MerkelMain
{
public:
    MerkelMain();

    void init();

private:
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);

    std::string currentTime;

    OrderBook orderBook = OrderBook("20200317.csv");

    Wallet wallet;
};