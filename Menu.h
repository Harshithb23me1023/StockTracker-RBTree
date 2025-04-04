#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu {
public:
    void displayMainMenu();
    void handleUserInput();
    void showStockOptions();
    void showFileOptions();
    void showStatisticsOptions();
    void showHelpMenu();
    void showSettingsMenu();
    void exitProgram();
};

#endif // MENU_H
