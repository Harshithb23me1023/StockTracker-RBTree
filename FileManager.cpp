#include "FileManager.h"

// Save Stock Data to File
void FileManager::saveToFile(const string& filename, RedBlackTree& tree) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    tree.saveToFileHelper(tree.getRoot(), file);
    file.close();
    cout << "Stock data saved to " << filename << " successfully!" << endl;
}

// Load Stock Data from File
void FileManager::loadFromFile(const string& filename, RedBlackTree& tree) {
    ifstream file(filename);
    if (!file) {
        cout << "No existing stock data found. Starting fresh.\n";
        return;
    }

    string symbol;
    double price;
    
    while (file >> symbol >> price) {
        tree.insert(symbol, price);
    }
    
    file.close();
    cout << "Stock data loaded from " << filename << " successfully!" << endl;
}
