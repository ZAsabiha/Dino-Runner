#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "MainMenu.h"
#include "Utility.h" 
#include "Global.h"
using namespace std;


void MainMenu::display() {  
    gameState.score.loadHighScore();
    while (true) {
        system("cls");
        gameState.ui.displayGameTitle();

        Utility::gotoxy(55, 15); cout << "\033[1;31m1. Play\033[0m";
        Utility::gotoxy(55, 19); cout << "\033[1;33m2. Instructions\033[0m";
        Utility::gotoxy(55, 22); cout << "\033[1;32m3. Select Dino\033[0m";
        Utility::gotoxy(55, 25); cout << "\033[1;34m4. Shop\033[0m"; 
        Utility::gotoxy(55, 28); cout << "\033[1;35m5. Exit\033[0m";
        Utility::gotoxy(55, 30); cout << "Select an option: ";

        char option;
        cin >> option;

        switch (option) {
            case '1':
            gameState.gc.play();
                break;
            case '2':
            gameState.ui.instructions();
                break;
            case '3':
            gameState.dino.selectDino();
                break;
            case '4':
            gameState.shop.shopMenu(); 
                break;
            case '5':
                exit(0);
                break;
            default:
                cout << "Invalid option! Please try again.";
                getch();
                break;
        }
    }
}
