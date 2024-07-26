#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

CSVReader::CSVReader()
{
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile(csvFilename);
    std::string line;

    if (!csvFile.is_open())
    {
        std::cout << "Problem opening file " << csvFilename << std::endl;
        return entries;
    }

    while (getline(csvFile, line))
    {
        std::vector<std::string> tokens = tokenise(line, ',');

        if (tokens.size() != 5)
        {
            std::cout << "Skipping line with incorrect number of tokens: " << line << std::endl;
            continue;
        }

        try
        {
            OrderBookEntry obe = stringsToOBE(tokens);
            entries.push_back(obe);
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception caught while processing line: " << e.what() << std::endl;
            continue;
        }
    }

    csvFile.close();
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    std::stringstream ss(csvLine);
    std::string token;

    while (getline(ss, token, separator))
    {
        tokens.push_back(token);
    }

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price, amount;
    if (tokens.size() != 5)
    {
        throw std::invalid_argument("Incorrect number of tokens");
    }

    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught while converting tokens to doubles: " << e.what() << std::endl;
        throw; // Rethrow the exception to the caller
    }

    return OrderBookEntry{
        tokens[0],                                        // timestamp
        tokens[1],                                        // product
        OrderBookEntry::stringToOrderBookType(tokens[2]), // order type
        price,                                            // price
        amount                                            // amount
    };
}

OrderBookEntry CSVReader::stringsToOBE(std::string priceString, std::string amountString, std::string timestamp, std::string product, OrderBookType orderType)
{
    double price, amount;
    try
    {
        price = std::stod(priceString);
        amount = std::stod(amountString);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught while converting tokens to doubles: " << e.what() << std::endl;
        throw;
    }
    return OrderBookEntry(timestamp, product, orderType, price, amount);
}
