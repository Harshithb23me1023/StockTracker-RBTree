#include "Menu.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructor
Menu::Menu(RedBlackTree& tree) : stockTree(tree) {}

// Display main menu
void Menu::displayMenu() {
    int choice;
    do {
        cout << "\nStock Market System Menu" << endl;
        cout << "1. Insert Stock" << endl;
        cout << "2. Search Stock" << endl;
        cout << "3. Display Stocks" << endl;
        cout << "4. Save to File" << endl;
        cout << "5. Load from File" << endl;
        cout << "6. Display Stock Statistics" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number: ";
            cin >> choice;
        }

        handleChoice(choice);
    } while (choice != 7);
}

// Handle user choices
void Menu::handleChoice(int choice) {
    string symbol;
    double price;
    string filename;

    switch (choice) {
        case 1:
            cout << "Enter stock symbol: ";
            cin >> symbol;
            cout << "Enter stock price: ";
            cin >> price;
            stockTree.insert(symbol, price);
            cout << "Stock inserted successfully." << endl;
            break;
        case 2:
            cout << "Enter stock symbol to search: ";
            cin >> symbol;
            stockTree.searchStock(symbol);
            break;
        case 3:
            cout << "Stock List (Inorder):" << endl;
            stockTree.displayInOrder();
            break;
        case 4:
            cout << "Enter filename to save: ";
            cin >> filename;
            stockTree.saveToFile(filename);
            cout << "Stock data saved successfully." << endl;
            break;
        case 5:
            cout << "Enter filename to load: ";
            cin >> filename;
            stockTree.loadFromFile(filename);
            cout << "Stock data loaded successfully." << endl;
            break;
        case 6:
            stockTree.displayStockStatistics();
            break;
        case 7:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
}

// Function to clear the screen
void Menu::clearScreen() {
    cout << string(50, '\n');
}

// Function to pause the screen
void Menu::pauseScreen() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

// Function to display stock with highest price
void Menu::displayHighestStock() {
    Node* maxStock = stockTree.getMaxStock();
    if (maxStock)
        cout << "Highest Stock: " << maxStock->stockSymbol << " - $" << maxStock->stockPrice << endl;
    else
        cout << "No stocks available." << endl;
}

// Function to display stock with lowest price
void Menu::displayLowestStock() {
    Node* minStock = stockTree.getMinStock();
    if (minStock)
        cout << "Lowest Stock: " << minStock->stockSymbol << " - $" << minStock->stockPrice << endl;
    else
        cout << "No stocks available." << endl;
}

// Extended statistics display
void Menu::extendedStockStatistics() {
    cout << "Stock Market Statistics" << endl;
    cout << "----------------------------" << endl;
    displayHighestStock();
    displayLowestStock();
    cout << "----------------------------" << endl;
    stockTree.displayStockStatistics();
}
