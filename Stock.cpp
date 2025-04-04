#include "Stock.h"
#include <iostream>
using namespace std;

// Constructor
Stock::Stock(string symbol, double price, string name, string sector) {
    stockSymbol = symbol;
    stockPrice = price;
    companyName = name;
    this->sector = sector;
}

// Getter for stock symbol
string Stock::getStockSymbol() {
    return stockSymbol;
}

// Getter for stock price
double Stock::getStockPrice() {
    return stockPrice;
}

// Getter for company name
string Stock::getCompanyName() {
    return companyName;
}

// Getter for sector
string Stock::getSector() {
    return sector;
}

// Setter for stock price
void Stock::setStockPrice(double price) {
    stockPrice = price;
}

// Setter for company name
void Stock::setCompanyName(string name) {
    companyName = name;
}

// Setter for sector
void Stock::setSector(string sector) {
    this->sector = sector;
}

// Display stock details
void Stock::displayStock() {
    cout << "Stock Symbol: " << stockSymbol << "\n";
    cout << "Company Name: " << companyName << "\n";
    cout << "Sector: " << sector << "\n";
    cout << "Stock Price: $" << stockPrice << "\n";
}

// Function to compare two stocks based on price
bool Stock::compareStock(Stock otherStock) {
    return this->stockPrice > otherStock.getStockPrice();
}

// Function to check if stock belongs to a sector
bool Stock::isSector(string sector) {
    return this->sector == sector;
}
