#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

class Menu {
private:
    RedBlackTree& stockTree;

public:
    Menu(RedBlackTree& tree) : stockTree(tree) {}
    void displayMenu();
    void handleChoice(int choice);
    void clearScreen();
    void pauseScreen();
    void displayHighestStock();
    void displayLowestStock();
    void extendedStockStatistics();
};

#endif // MENU_H
