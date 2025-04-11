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

// ✅ New: Search method returning Node*
Node* RedBlackTree::search(string symbol) {
    Node* current = root;
    while (current != NIL) {
        if (symbol == current->stockSymbol)
            return current;
        else if (symbol < current->stockSymbol)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}

// ✅ New: Return root
Node* RedBlackTree::getRoot() const {
    return root;
}

// ✅ New: Simple display method
void RedBlackTree::display() const {
    inorderTraversal(root);
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

// Additional utility functions added for debugging
void RedBlackTree::printTree() {
    printHelper(root, "", true);
}

void RedBlackTree::printHelper(Node* node, string indent, bool last) {
    if (node != NIL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        string color = node->color == RED ? "RED" : "BLACK";
        cout << node->stockSymbol << "(" << color << ")\n";
        printHelper(node->left, indent, false);
        printHelper(node->right, indent, true);
    }
}

// New function to count the total number of stocks
int RedBlackTree::countStocks(Node* node) {
    if (node == NIL)
        return 0;
    return 1 + countStocks(node->left) + countStocks(node->right);
}

int RedBlackTree::getTotalStocks() {
    return countStocks(root);
}

// Enhanced debugging function to check the tree structure
void RedBlackTree::validateRBTree() {
    if (root->color != BLACK) {
        cout << "Error: Root is not black!\n";
    }
    validateNode(root);
}

void RedBlackTree::validateNode(Node* node) {
    if (node == NIL)
        return;
    if (node->color == RED) {
        if (node->left->color == RED || node->right->color == RED) {
            cout << "Error: Red node " << node->stockSymbol << " has red children!\n";
        }
    }
    validateNode(node->left);
    validateNode(node->right);
}

// New function to find the stock with the highest price
Node* RedBlackTree::findMaxStock(Node* node) {
    while (node->right != NIL)
        node = node->right;
    return node;
}

Node* RedBlackTree::getMaxStock() {
    return findMaxStock(root);
}

// New function to find the stock with the lowest price
Node* RedBlackTree::findMinStock(Node* node) {
    while (node->left != NIL)
        node = node->left;
    return node;
}

Node* RedBlackTree::getMinStock() {
    return findMinStock(root);
}

// New function to calculate the total stock value
double RedBlackTree::calculateTotalStockValue(Node* node) {
    if (node == NIL)
        return 0;
    return node->stockPrice + calculateTotalStockValue(node->left) + calculateTotalStockValue(node->right);
}

double RedBlackTree::getTotalStockValue() {
    return calculateTotalStockValue(root);
}

// New function to calculate the average stock price
double RedBlackTree::calculateAverageStockPrice() {
    int totalStocks = getTotalStocks();
    return totalStocks == 0 ? 0 : getTotalStockValue() / totalStocks;
}

// New function to display stock statistics
void RedBlackTree::displayStockStatistics() {
    cout << "Total Stocks: " << getTotalStocks() << "\n";
    cout << "Total Stock Value: $" << getTotalStockValue() << "\n";
    cout << "Average Stock Price: $" << calculateAverageStockPrice() << "\n";
}
