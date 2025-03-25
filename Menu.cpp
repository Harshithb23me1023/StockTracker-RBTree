#include "Menu.h"

// Display the interactive menu
void Menu::displayMenu(RedBlackTree& tree) {
    int choice;
    string symbol;
    double price;

    do {
        cout << "\n===== STOCK MARKET SYSTEM =====\n";
        cout << "1. Insert a Stock\n";
        cout << "2. Delete a Stock\n";
        cout << "3. Search for a Stock\n";
        cout << "4. Display All Stocks\n";
        cout << "5. Save Data to File\n";
        cout << "6. Load Data from File\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Stock Symbol: ";
                cin >> symbol;
                cout << "Enter Stock Price: ";
                cin >> price;
                tree.insert(symbol, price);
                cout << "Stock added successfully!\n";
                break;

            case 2:
                cout << "Enter Stock Symbol to Delete: ";
                cin >> symbol;
                tree.remove(symbol);
                cout << "Stock deleted successfully!\n";
                break;

            case 3:
                cout << "Enter Stock Symbol to Search: ";
                cin >> symbol;
                if (tree.search(symbol) != nullptr)
                    cout << "Stock found: " << symbol << "\n";
                else
                    cout << "Stock not found!\n";
                break;

            case 4:
                cout << "\nStock Market Data:\n";
                tree.display();
                break;

            case 5:
                FileManager::saveToFile("data/stocks_data.txt", tree);
                cout << "Data saved successfully!\n";
                break;

            case 6:
                FileManager::loadFromFile("data/stocks_data.txt", tree);
                cout << "Data loaded successfully!\n";
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);
}
