#include "RedBlackTree.h"

// Constructor
RedBlackTree::RedBlackTree() {
    NIL = new Node("", 0);
    NIL->color = BLACK;
    root = NIL;
}

// Destructor
RedBlackTree::~RedBlackTree() {
    deleteTree(root);
}

// Insert stock
void RedBlackTree::insert(string symbol, double price) {
    Node* newNode = new Node(symbol, price);
    Node* parent = nullptr;
    Node* current = root;

    while (current != NIL) {
        parent = current;
        if (symbol < current->stockSymbol)
            current = current->left;
        else if (symbol > current->stockSymbol)
            current = current->right;
        else {
            current->stockPrice = price;
            return;
        }
    }

    newNode->parent = parent;
    if (parent == nullptr)
        root = newNode;
    else if (symbol < parent->stockSymbol)
        parent->left = newNode;
    else
        parent->right = newNode;

    newNode->left = NIL;
    newNode->right = NIL;
    newNode->color = RED;

    fixInsert(root, newNode);
}

// Search for a stock
void RedBlackTree::searchStock(string symbol) {
    Node* current = root;
    while (current != NIL) {
        if (symbol == current->stockSymbol) {
            cout << "Stock Found: " << symbol << " - $" << current->stockPrice << "\n";
            return;
        } else if (symbol < current->stockSymbol) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Stock Not Found.\n";
}

// Display Inorder (sorted order)
void RedBlackTree::displayInOrder() {
    inorderTraversal(root);
}

// Inorder Traversal Helper
void RedBlackTree::inorderTraversal(Node* node) {
    if (node != NIL) {
        inorderTraversal(node->left);
        cout << node->stockSymbol << " - $" << node->stockPrice << "\n";
        inorderTraversal(node->right);
    }
}

// Save to file
void RedBlackTree::saveToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        saveToFileHelper(root, file);
        file.close();
    }
}

// Save to file helper
void RedBlackTree::saveToFileHelper(Node* node, ofstream& file) {
    if (node != NIL) {
        file << node->stockSymbol << " " << node->stockPrice << "\n";
        saveToFileHelper(node->left, file);
        saveToFileHelper(node->right, file);
    }
}
