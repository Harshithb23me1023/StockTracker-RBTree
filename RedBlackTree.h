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
    void inorderTraversal(Node* node);
    void deleteTree(Node* node);
    void saveToFileHelper(Node* node, ofstream& file);
    void loadFromFileHelper(ifstream& file);

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
};

#endif
