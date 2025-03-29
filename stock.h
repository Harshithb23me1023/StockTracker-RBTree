#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

using namespace std;

class Stock {
private:
    string symbol;  // Stock symbol (e.g., AAPL, TSLA)
    double price;   // Stock price

public:
    // Constructors
    Stock();
    Stock(string symbol, double price);

    // Getters and Setters
    string getSymbol() const;
    double getPrice() const;
    void setPrice(double newPrice);

    // Display stock details
    void displayStock() const;

    // Overload comparison operators (for Red-Black Tree)
    bool operator<(const Stock& other) const;
    bool operator>(const Stock& other) const;
    bool operator==(const Stock& other) const;
};

#endif
