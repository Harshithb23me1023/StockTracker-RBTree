#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::saveToFile(const string& filename, RedBlackTree& tree) {
    tree.saveToFile(filename); // call internal function
}


void FileManager::loadFromFile(const string& filename, RedBlackTree& tree) {
    ifstream file(filename);
    if (file.is_open()) {
        tree.loadFromFile(filename);
        file.close();
    } else {
        logError("Unable to open file for reading: " + filename);
    }
}

bool FileManager::fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void FileManager::logError(const string& errorMessage) {
    cerr << "Error: " << errorMessage << endl;
}
