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

void RedBlackTree::deleteNode(Node* node, const string& symbol) {
    Node* z = NIL;
    Node* x, *y;
    while (node != NIL) {
        if (node->stockSymbol == symbol)
            z = node;
        node = (symbol < node->stockSymbol) ? node->left : node->right;
    }

    if (z == NIL) return;

    y = z;
    Color yOriginalColor = y->color;
    if (z->left == NIL) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = minimum(z->right);
        yOriginalColor = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;
    if (yOriginalColor == BLACK)
        fixDelete(x);
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

       // Rest of insert logic...
       newNode->left = NIL;
       newNode->right = NIL;
       newNode->color = RED;
   
       fixInsert(newNode); // <-- Fix the tree after insert
   }
   

void RedBlackTree::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return;
    }

    std::string symbol;
    double price;
    while (file >> symbol >> price) {
        insert(symbol, price);
    }

    file.close();
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


void RedBlackTree::saveToFile(const string& filename) const {
    ofstream file(filename, ios::trunc); // trunc clears existing
    if (file.is_open()) {
        saveHelper(root, file);
        file.close();
    } else {
        cerr << "Failed to open file for writing.\n";
    }
}


void RedBlackTree::saveHelper(Node* node, std::ofstream& file) const {
    if (node != NIL) {
        file << node->stockSymbol << " " << node->stockPrice << "\n";
        saveHelper(node->left, file);
        saveHelper(node->right, file);
    }
}

void RedBlackTree::remove(string symbol) {
    Node* node = search(symbol);
    if (node == nullptr || node == NIL) {
        cout << "Stock not found.\n";
        return;
    }
    deleteNode(root, symbol);
}

void RedBlackTree::searchStock(string stockSymbol) {
    Node* current = root;
    while (current != nullptr) {
        if (stockSymbol == current->stockSymbol) {
            cout << "Stock found: " << stockSymbol << " - Price: $" << current->stockPrice << endl;
            return;
        } else if (stockSymbol < current->stockSymbol) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Stock not found: " << stockSymbol << endl;
}

void RedBlackTree::updateStockPrice(string stockSymbol, double newPrice) {
    Node* current = root;
    while (current != nullptr) {
        if (stockSymbol == current->stockSymbol) {
            current->stockPrice = newPrice;
            cout << "Stock price updated for " << stockSymbol << ": $" << newPrice << endl;
            return;
        } else if (stockSymbol < current->stockSymbol) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Stock not found to update: " << stockSymbol << endl;
}

void RedBlackTree::displayInOrder() const {

    
    inorderHelper(root);
    cout << endl;
}

void RedBlackTree::displayTreeStructure() const {
    printTreeHelper(root, "", true);
}

void RedBlackTree::deleteTree(Node* node) {
    if (node != NIL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

Node* RedBlackTree::minimum(Node* node) const {
    while (node->left != NIL)
        node = node->left;
    return node;
}

void RedBlackTree::fixDelete(Node* x) {
    Node* s;
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == RED) {
                s->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == BLACK && s->right->color == BLACK) {
                s->color = RED;
                x = x->parent;
            } else {
                if (s->right->color == BLACK) {
                    s->left->color = BLACK;
                    s->color = RED;
                    rotateRight(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->color == RED) {
                s->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == BLACK && s->left->color == BLACK) {
                s->color = RED;
                x = x->parent;
            } else {
                if (s->left->color == BLACK) {
                    s->right->color = BLACK;
                    s->color = RED;
                    rotateLeft(s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = BLACK;
                s->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

