#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

// Constructor
FileManager::FileManager(string filename) {
    this->filename = filename;
}

// Save stock data to file
void FileManager::saveToFile(vector<pair<string, double>> &stocks) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }
    for (auto &stock : stocks) {
        file << stock.first << " " << stock.second << endl;
    }
    file.close();
}

// Load stock data from file
void FileManager::loadFromFile(vector<pair<string, double>> &stocks) {
    ifstream file(filename);
    if (!file) {
        cerr << "Warning: File not found, starting fresh." << endl;
        return;
    }
    stocks.clear();
    string symbol;
    double price;
    while (file >> symbol >> price) {
        stocks.emplace_back(symbol, price);
    }
    file.close();
}

// Check if file exists
bool FileManager::fileExists() {
    ifstream file(filename);
    return file.good();
}

// Delete stock file
bool FileManager::deleteFile() {
    if (remove(filename.c_str()) == 0) {
        cout << "File deleted successfully." << endl;
        return true;
    } else {
        cerr << "Error deleting file." << endl;
        return false;
    }
}

// Append stock data
void FileManager::appendToFile(string symbol, double price) {
    ofstream file(filename, ios::app);
    if (!file) {
        cerr << "Error: Unable to open file for appending!" << endl;
        return;
    }
    file << symbol << " " << price << endl;
    file.close();
}

// Backup existing stock file
void FileManager::backupFile() {
    ifstream src(filename, ios::binary);
    if (!src) {
        cerr << "No file to backup!" << endl;
        return;
    }
    ofstream dest(filename + ".bak", ios::binary);
    dest << src.rdbuf();
    cout << "Backup created: " << filename << ".bak" << endl;
}

// Read entire file contents
string FileManager::readFileContents() {
    ifstream file(filename);
    if (!file) {
        return "Error: Unable to read file!";
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Log activity
void FileManager::logActivity(string message) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error: Unable to open log file!" << endl;
        return;
    }
    time_t now = time(0);
    logFile << ctime(&now) << " - " << message << endl;
}
