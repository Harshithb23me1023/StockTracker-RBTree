#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Stock.h"
#include "RedBlackTree.h"

using namespace std;

class FileManager {
public:
    // Save stocks to a file
    static void saveToFile(const string& filename, RedBlackTree& tree);

    // Load stocks from a file
    static void loadFromFile(const string& filename, RedBlackTree& tree);
};

#endif
