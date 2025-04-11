#include "RedBlackTree.h"
#include <fstream>

RedBlackTree::RedBlackTree() {
    NIL = new Node("", 0.0);
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NIL;
    root = NIL;
}

RedBlackTree::~RedBlackTree() {
    deleteTree(root);
    delete NIL;
}

void RedBlackTree::deleteTree(Node* node) {
    if (node != NIL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

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
            // Update existing stock
            current->stockPrice = price;
            delete newNode;
            return;
        }
    }

    newNode->parent = parent;
    if (parent == nullptr) {
        root = newNode;
    } else if (symbol < parent->stockSymbol) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    newNode->left = NIL;
    newNode->right = NIL;
    newNode->color = RED;

    fixInsert(newNode);
}

void RedBlackTree::fixInsert(Node* node) {
    while (node != root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(node->parent->parent);
            }
        } else {
            // Mirror case
            Node* uncle = node->parent->parent->left;
            if (uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::rotateLeft(Node* node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;
    
    if (rightChild->left != NIL)
        rightChild->left->parent = node;
        
    rightChild->parent = node->parent;
    
    if (node->parent == nullptr)
        root = rightChild;
    else if (node == node->parent->left)
        node->parent->left = rightChild;
    else
        node->parent->right = rightChild;
        
    rightChild->left = node;
    node->parent = rightChild;
}

void RedBlackTree::rotateRight(Node* node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;
    
    if (leftChild->right != NIL)
        leftChild->right->parent = node;
        
    leftChild->parent = node->parent;
    
    if (node->parent == nullptr)
        root = leftChild;
    else if (node == node->parent->right)
        node->parent->right = leftChild;
    else
        node->parent->left = leftChild;
        
    leftChild->right = node;
    node->parent = leftChild;
}

Node* RedBlackTree::search(string symbol) const {
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

void RedBlackTree::inorderHelper(Node* node) const {
    if (node != NIL) {
        inorderHelper(node->left);
        cout << node->stockSymbol << ": $" << node->stockPrice << endl;
        inorderHelper(node->right);
    }
}

void RedBlackTree::printTreeHelper(Node* node, string indent, bool last) const {
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
        cout << node->stockSymbol << "(" << color << ")" << endl;
        printTreeHelper(node->left, indent, false);
        printTreeHelper(node->right, indent, true);
    }
}

void RedBlackTree::saveToFile(string filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        saveHelper(root, file);
        file.close();
    }
}

void RedBlackTree::saveHelper(Node* node, ofstream& file) const {
    if (node != NIL) {
        file << node->stockSymbol << " " << node->stockPrice << "\n";
        saveHelper(node->left, file);
        saveHelper(node->right, file);
    }
}
