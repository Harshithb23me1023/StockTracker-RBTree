#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "RedBlackTree.h"
#include "FileManager.h"

using namespace std;

class Menu {
public:
    // Function to display menu options
    static void displayMenu(RedBlackTree& tree);
};

#endif
