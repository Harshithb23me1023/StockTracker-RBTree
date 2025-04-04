#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Stock.h"

using namespace std;

class FileManager {
public:
    FileManager();
    ~FileManager();
    
    bool saveToFile(const string& filename, const vector<Stock>& stocks);
    bool loadFromFile(const string& filename, vector<Stock>& stocks);
    bool fileExists(const string& filename);
    void clearFile(const string& filename);
    
    void printFileContents(const string& filename);
    bool validateFileFormat(const string& filename);
    void logError(const string& errorMessage);
    
private:
    void createBackup(const string& filename);
};

#endif // FILEMANAGER_H
