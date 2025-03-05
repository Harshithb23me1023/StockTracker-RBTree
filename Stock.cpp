#include "Stock.h"

// Default Constructor
Stock::Stock() {
    symbol = "";
    price = 0.0;
}

// Parameterized Constructor
Stock::Stock(string symbol, double price) {
    this->symbol = symbol;
    this->price = price;
}

// Getters
string Stock::getSymbol() const {
    return symbol;
}

double Stock::getPrice() const {
    return price;
}

// Setter for stock price
void Stock::setPrice(double newPrice) {
    price = newPrice;
}

// Display stock details
void Stock::displayStock() const {
    cout << "Stock: " << symbol << " | Price: $" << price << endl;
}

// Overloaded comparison operators for sorting in Red-Black Tree
bool Stock::operator<(const Stock& other) const {
    return symbol < other.symbol;
}

bool Stock::operator>(const Stock& other) const {
    return symbol > other.symbol;
}

bool Stock::operator==(const Stock& other) const {
    return symbol == other.symbol;
}
