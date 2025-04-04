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

    // Additional helper functions
    void printTreeStructure(Node* node, string indent, bool last); // Debug function
    int countNodes(Node* node); // Count total nodes in the tree
    int getTreeHeight(Node* node); // Get height of the tree
    Node* findMaxValueNode(Node* node); // Find maximum value node
    
public:
    RedBlackTree();
    ~RedBlackTree();
    void insert(string symbol, double price);
    void remove(string symbol);
    void searchStock(string symbol);
    void updateStockPrice(string symbol, double price);
    void displayInOrder();
    void saveToFile(string filename);
    void loadFromFile(string filename);

    // Public utility functions
    void printTree(); // Print tree structure for debugging
    int getTotalStocks(); // Get total number of stocks in the tree
    int getHeight(); // Get height of the Red-Black Tree
    string getMaxStock(); // Get stock with the highest value
};

#endif
