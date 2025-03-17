
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Shop.h"
#include "Utility.h"
#include "Global.h"

void Shop::shopMenu() {
    while (true) {
        Utility::clearScreen();
        Utility::gotoxy(55, 10);
        std::cout << "\033[1;36mWelcome to the Shop!\033[0m";
        Utility::gotoxy(55, 13);
        std::cout << "Your Score: " << gameState.currentScore;
        Utility::gotoxy(55, 15);
        std::cout << "\033[1;31m1. Buy Extra Life (Cost: 10 points)\033[0m";
        Utility::gotoxy(55, 17);
        std::cout << "\033[1;32m2. Buy Speed Boost (Cost: 5 points)\033[0m";
        Utility::gotoxy(55, 19);
        std::cout << "\033[1;33m3. Buy Horizontal Weapon (Cost: 3 points)\033[0m";
        Utility::gotoxy(55, 21);
        std::cout << "\033[1;33m4. Buy Vertical Weapon (Cost: 4 points)\033[0m";
        Utility::gotoxy(55, 23);
        std::cout << "\033[1;34m5. Back to Game\033[0m";
        Utility::gotoxy(55, 25);
        std::cout << "Select an option: ";

        char option;
        std::cin >> option;

        switch (option) {
            case '1':
                if (gameState.currentScore >= 10) {
                    gameState.lives++;
                    gameState.currentScore -= 10;
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;32mExtra life purchased!\033[0m";
                } else {
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '2':
                if (gameState.currentScore >= 5) {
                    gameState.speed = std::max(gameState.speed - 5, 20);
                    gameState.currentScore -= 5;
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;32mSpeed boost purchased!\033[0m";
                } else {
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '3':
                if (gameState.currentScore >= 3) {
                    gameState.horizontalWeaponActive = true;
                    gameState.horizontalMissileCount = 1;
                    gameState.currentScore -= 3;
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;32mHorizontal weapon activated (3 uses)!\033[0m";
                } else {
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '4':
                if (gameState.currentScore >= 4) {
                    gameState.verticalWeaponActive = true;
                    gameState.verticalMissileCount = 1;
                    gameState.currentScore -= 4;
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;32mVertical weapon activated (3 uses)!\033[0m";
                } else {
                    Utility::gotoxy(55, 25);
                    std::cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '5':
                return; 
            default:
                Utility::gotoxy(55, 25);
                std::cout << "\033[1;31mInvalid option! Please try again.\033[0m";
                break;
        }
        getch(); 
    }
}
