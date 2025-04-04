#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
using namespace std;

class Stock {
private:
    string symbol;
    double price;
    int quantity;
    string companyName;
    string sector;

public:
    // Constructor
    Stock(string sym, double pr, int qty, string name, string sec)
        : symbol(sym), price(pr), quantity(qty), companyName(name), sector(sec) {}

    // Getters
    string getSymbol() const { return symbol; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    string getCompanyName() const { return companyName; }
    string getSector() const { return sector; }

    // Setters
    void setPrice(double pr) { price = pr; }
    void setQuantity(int qty) { quantity = qty; }
    void setCompanyName(string name) { companyName = name; }
    void setSector(string sec) { sector = sec; }

    // Display stock information
    void displayStock() const {
        cout << "Stock: " << symbol << " | Company: " << companyName 
             << " | Sector: " << sector << " | Price: $" << price
             << " | Quantity: " << quantity << endl;
    }
};

#endif // STOCK_H
