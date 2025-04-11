#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Enum for node color in Red-Black Tree
enum Color { RED, BLACK };

// Node structure for the Red-Black Tree
struct Node {
    string stockSymbol;
    double stockPrice;
    Node* left;
    Node* right;
    Node* parent;
    Color color;

    Node(string symbol, double price) {
        stockSymbol = symbol;
        stockPrice = price;
        left = right = parent = nullptr;
        color = RED;
    }
};

class RedBlackTree {
private:
    Node* root;
    Node* NIL;

    void rotateLeft(Node*& root, Node*& node);
    void rotateRight(Node*& root, Node*& node);
    void fixInsert(Node*& root, Node*& node);
    void fixDelete(Node*& root, Node*& node);
    Node* minValueNode(Node* node);
    void inorderTraversal(Node* node);
    void deleteTree(Node* node);
    void saveToFileHelper(Node* node, ofstream& file);
    void loadFromFileHelper(ifstream& file);
    void printHelper(Node* node, string indent, bool last);
    void validateNode(Node* node);
    int countStocks(Node* node);
    Node* findMaxStock(Node* node);
    Node* findMinStock(Node* node);
    double calculateTotalStockValue(Node* node);

public:
    RedBlackTree();
    ~RedBlackTree();

    // Core operations
    void insert(string symbol, double price);
    void remove(string symbol);
    void searchStock(string symbol);
    void updateStockPrice(string symbol, double price);
    Node* search(string symbol); // Returns pointer to node
    Node* getRoot() const;

    // Display
    void display() const;
    void displayInOrder();
    void printTree(); // Print tree structure (debug)
    void displayTreeStructure() { printTree(); }

    // File operations
    void saveToFile(string filename);
    void loadFromFile(string filename);

    // Statistics
    int getTotalStocks();
    double getTotalStockValue();
    double calculateAverageStockPrice();
    void displayStockStatistics();
    Node* getMaxStock();
    Node* getMinStock();

    // Tree integrity
    void validateRBTree();
};

#endif
