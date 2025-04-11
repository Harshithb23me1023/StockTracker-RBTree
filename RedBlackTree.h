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
    void inorderTraversal(Node* node) const;
    void deleteTree(Node* node);
    void saveToFileHelper(Node* node, ofstream& file) const;
    void printHelper(Node* node, string indent, bool last) const;
    void validateNode(Node* node) const;
    int countStocks(Node* node) const;
    Node* findMaxStock(Node* node) const;
    Node* findMinStock(Node* node) const;
    double calculateTotalStockValue(Node* node) const;

public:
    RedBlackTree();
    ~RedBlackTree();

    void insert(string symbol, double price);
    void remove(string symbol);
    void searchStock(string symbol) const;
    void updateStockPrice(string symbol, double price);
    Node* search(string symbol) const;
    Node* getRoot() const;

    void display() const { inorderTraversal(root); }
    void displayInOrder() const { inorderTraversal(root); }
    void printTree() const { printHelper(root, "", true); }
    void displayTreeStructure() const { printTree(); }

    void saveToFile(string filename) const;
    void loadFromFile(string filename);

    int getTotalStocks() const { return countStocks(root); }
    double getTotalStockValue() const { return calculateTotalStockValue(root); }
    double calculateAverageStockPrice() const;
    void displayStockStatistics() const;
    Node* getMaxStock() const { return findMaxStock(root); }
    Node* getMinStock() const { return findMinStock(root); }

    void validateRBTree() const;
};

#endif
