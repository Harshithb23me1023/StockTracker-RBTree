#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;

class Stock {
private:
    string stockSymbol;
    double stockPrice;
    string companyName;
    string sector;

public:
    // Constructor
    Stock(string symbol, double price, string name = "", string sector = "");

    // Getters
    string getStockSymbol();
    double getStockPrice();
    string getCompanyName() const;
    string getSector() const;

    // Setters
    void setStockPrice(double price);
    void setCompanyName(string name);
    void setSector(string sec);

    // Display
    void displayStock() const;

    // Comparison functions
    bool compareStock(Stock otherStock);
    bool isSector(string sector);
};

#endif // STOCK_H
