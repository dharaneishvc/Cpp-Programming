#include "MerkelMain.h"

int main()
{
    MerkelMain app{};
    app.init();
    return 0;
}

// to compile use the command in terminal
// g++ -std=c++11 src/main.cpp src/MerkelMain.cpp src/OrderBook.cpp src/OrderBookEntry.cpp src/CSVReader.cpp src/Wallet.cpp
