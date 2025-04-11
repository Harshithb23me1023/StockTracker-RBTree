#include "Stock.h"
#include <iostream>
using namespace std;

// Constructor
Stock::Stock(string symbol, double price, string name, string sec) {
    stockSymbol = symbol;
    stockPrice = price;
    companyName = name;
    sector = sec;
}

// Getters
string Stock::getStockSymbol() {
    return stockSymbol;
}

double Stock::getStockPrice() {
    return stockPrice;
}

string Stock::getCompanyName() const {
    return companyName;
}

string Stock::getSector() const {
    return sector;
}

// Setters
void Stock::setStockPrice(double price) {
    stockPrice = price;
}

void Stock::setCompanyName(string name) {
    companyName = name;
}

void Stock::setSector(string sec) {
    sector = sec;
}

// Display
void Stock::displayStock() const {
    cout << "Stock Symbol: " << stockSymbol << "\n";
    cout << "Company Name: " << companyName << "\n";
    cout << "Sector: " << sector << "\n";
    cout << "Stock Price: $" << stockPrice << "\n";
}

// Comparison
bool Stock::compareStock(Stock otherStock) {
    return this->stockPrice > otherStock.getStockPrice();
}

bool Stock::isSector(string sec) {
    return this->sector == sec;
}
