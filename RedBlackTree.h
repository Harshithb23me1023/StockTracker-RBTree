#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    string stockSymbol;
    double stockPrice;
    Node *left, *right, *parent;
    Color color;

    Node(string symbol, double price)
        : stockSymbol(symbol), stockPrice(price), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};

class RedBlackTree {
private:
    Node *root, *NIL;

    void rotateLeft(Node* node);
    void rotateRight(Node* node);
    void fixInsert(Node* node);
    void fixDelete(Node* node);
    void transplant(Node* u, Node* v);
    void deleteNode(Node* node, const string& symbol);
    Node* minimum(Node* node) const;

    void inorderHelper(Node* node) const;
    void printTreeHelper(Node* node, string indent, bool last) const;
    void deleteTree(Node* node);

    void saveHelper(Node* node, ofstream& file) const;
    int countStocks(Node* node) const;
    double calculateTotalStockValue(Node* node) const;
    Node* findMinStock(Node* node) const;
    Node* findMaxStock(Node* node) const;

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(string symbol, double price);
    void remove(string stockSymbol);
    Node* search(string symbol) const;
    void searchStock(string stockSymbol);
    void updateStockPrice(string stockSymbol, double newPrice);

    void displayInOrder() const;
    void displayTreeStructure() const;

    void saveToFile(ofstream& file) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);

    int getTotalStocks() const;
    double getTotalStockValue() const;
    double calculateAverageStockPrice() const;
    void displayStockStatistics() const;

    Node* getMaxStock() const;
    Node* getMinStock() const;
};

#endif
