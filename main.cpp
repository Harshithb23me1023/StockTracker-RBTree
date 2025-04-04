#include <iostream>
#include <string>
#include "RedBlackTree.h"
#include "FileManager.h"
#include "Menu.h"

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n===== Stock Market Management System (RB-Tree) =====\n";
    cout << "1. Insert Stock\n";
    cout << "2. Delete Stock\n";
    cout << "3. Search Stock\n";
    cout << "4. Update Stock Price\n";
    cout << "5. Display Stocks (Inorder)\n";
    cout << "6. Save to File\n";
    cout << "7. Load from File\n";
    cout << "8. Display Tree Structure\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    RedBlackTree stockTree;
    FileManager fileManager;
    int choice;
    string stockSymbol;
    double stockPrice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Stock Symbol (e.g., AAPL): ";
                cin >> stockSymbol;
                cout << "Enter Stock Price: ";
                cin >> stockPrice;
                stockTree.insert(stockSymbol, stockPrice);
                cout << "Stock inserted successfully!\n";
                break;

            case 2:
                cout << "Enter Stock Symbol to Delete: ";
                cin >> stockSymbol;
                stockTree.remove(stockSymbol);
                cout << "Stock deleted (if found)!\n";
                break;

            case 3:
                cout << "Enter Stock Symbol to Search: ";
                cin >> stockSymbol;
                stockTree.searchStock(stockSymbol);
                break;

            case 4:
                cout << "Enter Stock Symbol to Update: ";
                cin >> stockSymbol;
                cout << "Enter New Stock Price: ";
                cin >> stockPrice;
                stockTree.updateStockPrice(stockSymbol, stockPrice);
                break;

            case 5:
                cout << "\nStock List (Inorder Traversal):\n";
                stockTree.displayInOrder();
                break;

            case 6:
                fileManager.saveToFile("data/stocks_data.txt", stockTree);
                cout << "Stock data saved successfully!\n";
                break;

            case 7:
                fileManager.loadFromFile("data/stocks_data.txt", stockTree);
                cout << "Stock data loaded successfully!\n";
                break;
            
            case 8:
                cout << "Displaying Red-Black Tree structure:\n";
                stockTree.displayTreeStructure();
                break;

            case 9:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
