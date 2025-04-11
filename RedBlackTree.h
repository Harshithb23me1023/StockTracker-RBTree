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

    // Helper functions
    void rotateLeft(Node* node);
    void rotateRight(Node* node);
    void fixInsert(Node* node);
    void fixDelete(Node* node);
    void transplant(Node* u, Node* v);
    Node* minimum(Node* node);
    void deleteTree(Node* node);
    void inorderHelper(Node* node) const;
    void printTreeHelper(Node* node, string indent, bool last) const;
    void saveHelper(Node* node, ofstream& file) const;
    
public:
    // Constructor/Destructor
    RedBlackTree();
    ~RedBlackTree();

    // Core operations
    void insert(string symbol, double price);
    void remove(string symbol);
    Node* search(string symbol) const;
    
    // Display functions
    void displayInOrder() const { inorderHelper(root); }
    void displayTreeStructure() const { printTreeHelper(root, "", true); }
    
    // File operations
    void saveToFile(string filename) const;
    void loadFromFile(string filename);
};

#endif
