#include "MerkelMain.h"
#include "CSVReader.h"
#include <iostream>

MerkelMain::MerkelMain()
{
    // Constructor if needed
}

void MerkelMain::init()
{
    currentTime = orderBook.getEarliestTime();
    wallet.insertCurrency("ETH", 10.0);

    int input;
    while (true)
    {
        std::cout << "Current Time: " << currentTime << std::endl;
        printMenu();
        try
        {
            input = getUserOption();
        }
        catch(const std::exception& e)
        {
            std::cerr<<"Error in Input" << e.what() << '\n';
        }
        
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    std::cout << "\n===== MENU =====" << std::endl;
    std::cout << "1. Print Help" << std::endl;
    std::cout << "2. Print Market Statistics" << std::endl;
    std::cout << "3. Enter Offer" << std::endl;
    std::cout << "4. Enter Bid" << std::endl;
    std::cout << "5. Print Wallet" << std::endl;
    std::cout << "6. Goto Next Timeframe" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "\n===== HELP =====" << std::endl;
    std::cout << "This is the help section." << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (const std::string &p : orderBook.getKnownProducts())
    {
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Product: " << p << std::endl;
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
}

void MerkelMain::enterAsk()
{
    std::cout << "\nMake an ask - enter the amount: product,price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    if (tokens.size() != 3)
    {
        std::cout << "Invalid input format. Please try again." << std::endl;
        return;
    }

    try
    {
        OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
        obe.username = "simuser";  // Set username for simulation user

        // Check if wallet can fulfill the ask order
        if (wallet.canFulfillOrder(obe))
        {
            orderBook.insertOrder(obe);
            std::cout << "Ask placed successfully." << std::endl;
        }
        else
        {
            std::cout << "Insufficient funds to place the ask order." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void MerkelMain::enterBid()
{
    std::cout << "\nMake a bid - enter the amount: product,price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');

    if (tokens.size() != 3)
    {
        std::cout << "Invalid input format. Please try again." << std::endl;
        return;
    }

    try
    {
        OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
        obe.username = "simuser"; // Set username for simulation user

        // Check if wallet can fulfill the ask order
        if (wallet.canFulfillOrder(obe))
        {
            orderBook.insertOrder(obe);
            std::cout << "Bid placed successfully." << std::endl;
            std::vector<std::string> tt = CSVReader::tokenise(tokens[0], '/');
            // Update the wallet: Deduct the amount of the ask currency
            wallet.removeCurrency(tt[0], std::stoi(tokens[1]) * std::stoi(tokens[2]));
        }
        else
        {
            std::cout << "Insufficient funds to place the bid order." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void MerkelMain::printWallet()
{
    std::cout << "\n===== WALLET =====" << std::endl;
    std::cout << wallet << std::endl;
    // Implement wallet printing
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame." << std::endl;

    for (const std::string &p : orderBook.getKnownProducts())
    {
        std::cout << "Matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);

        std::cout << "Sales: " << sales.size() << std::endl;

        for (OrderBookEntry &sale : sales)
        {
            std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;

            if (sale.username == "simuser")
            {
                wallet.processSale(sale); // Process sale for simulation user
            }
        }
    }

    currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 0-6" << std::endl;
    std::getline(std::cin, line);
    try
    {
        userOption = std::stoi(line);
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid input. Please try again." << std::endl;
    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
{
    switch (userOption)
    {
    case 0:
        std::cout << "\nExiting..." << std::endl;
        exit(0);
    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();
        break;
    case 3:
        enterAsk();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        gotoNextTimeframe();
        break;
    default:
        std::cout << "\nInvalid option. Please try again." << std::endl;
        break;
    }
}
