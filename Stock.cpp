#include "Stock.h"

Stock::Stock(string symbol, double price, string name, string sector)
    : stockSymbol(symbol), stockPrice(price), companyName(name), sector(sector) {}

string Stock::getStockSymbol() { return stockSymbol; }
double Stock::getStockPrice() { return stockPrice; }
string Stock::getCompanyName() const { return companyName; }
string Stock::getSector() const { return sector; }

void Stock::setStockPrice(double price) { stockPrice = price; }
void Stock::setCompanyName(string name) { companyName = name; }
void Stock::setSector(string sec) { sector = sec; }

bool Stock::compareStock(Stock otherStock) {
    return stockSymbol == otherStock.stockSymbol;
}

bool Stock::isSector(string sector) {
    return this->sector == sector;
}

// 🆕 Add this display function
void Stock::displayStock() const {
    cout << "Symbol: " << stockSymbol << endl;
    cout << "Company Name: " << companyName << endl;
    cout << "Sector: " << sector << endl;
    cout << "Price: " << stockPrice << endl;
    cout << "--------------------------" << endl;
}
