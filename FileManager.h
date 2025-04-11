#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "RedBlackTree.h"

using namespace std;

class FileManager {
public:
    FileManager() {}
    
    void saveToFile(const string& filename, RedBlackTree& tree);
    void loadFromFile(const string& filename, RedBlackTree& tree);
    bool fileExists(const string& filename);
    
private:
    void logError(const string& errorMessage);
};

#endif // FILEMANAGER_H
