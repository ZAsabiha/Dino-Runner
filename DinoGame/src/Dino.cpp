#include "Dino.h"
#include "Utility.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "global.h"




void Dino::moveDino(int jump, bool ducking) {
    static int foot = 0;
      

    if (jump == 0) {
        gameState.dinoY = 0;
    } else if (jump == 2) {
        gameState.dinoY--;  
   
    } else {
        gameState.dinoY++;  
     
    }


    
    if (gameState.selectedDino == 1) {
  
    Utility::gotoxy(dinoPos, 21 - gameState.dinoY); std::cout << "                      ";
    Utility::gotoxy(dinoPos, 22 - gameState.dinoY); std::cout << "             █████  ";
    Utility::gotoxy(dinoPos, 23 - gameState.dinoY); std::cout << "            ███░░██";
    Utility::gotoxy(dinoPos, 24 - gameState.dinoY); std::cout << "           ██████   ";
    Utility::gotoxy(dinoPos, 25 - gameState.dinoY); std::cout << "  █          ███";
    Utility::gotoxy(dinoPos, 26 - gameState.dinoY); std::cout << "  ██         ███ ";
    Utility::gotoxy(dinoPos, 27 - gameState.dinoY); std::cout << "   ███     █████          ";
    Utility::gotoxy(dinoPos, 28 - gameState.dinoY); std::cout << "     ██████████          ";
    Utility::gotoxy(dinoPos, 29 - gameState.dinoY); std::cout << "    ██████████          ";
    Utility::gotoxy(dinoPos, 30 - gameState.dinoY);
    } else if (gameState.selectedDino == 2) {
    
        Utility::gotoxy(dinoPos, 22 - gameState.dinoY); std::cout << "              ███  ";
        Utility::gotoxy(dinoPos, 23 - gameState.dinoY); std::cout << "            ███░░██";
        Utility::gotoxy(dinoPos, 24 - gameState.dinoY); std::cout << "             █████   ";
        Utility::gotoxy(dinoPos, 25 - gameState.dinoY); std::cout << "  █           ██";
        Utility::gotoxy(dinoPos, 26 - gameState.dinoY); std::cout << "  ██          ██ ";
        Utility::gotoxy(dinoPos, 27 - gameState.dinoY); std::cout << "   ███        ██          ";
        Utility::gotoxy(dinoPos, 28 - gameState.dinoY); std::cout << "      █████████          ";
        Utility::gotoxy(dinoPos, 29 - gameState.dinoY); std::cout << "        ███████          ";
        Utility::gotoxy(dinoPos, 30 - gameState.dinoY);
    } else if (gameState.selectedDino == 3) {
        
        Utility::gotoxy(dinoPos, 22 - gameState.dinoY); std::cout << "             █████  ";
        Utility::gotoxy(dinoPos, 23 - gameState.dinoY); std::cout << "            ███░░██";
        Utility::gotoxy(dinoPos, 24 - gameState.dinoY); std::cout << "           ██████   ";
        Utility::gotoxy(dinoPos, 25 - gameState.dinoY); std::cout << "            ███";
        Utility::gotoxy(dinoPos, 26 - gameState.dinoY); std::cout << "       ████████ ";
        Utility::gotoxy(dinoPos, 27 - gameState.dinoY); std::cout << "       ████████          ";
        Utility::gotoxy(dinoPos, 28 - gameState.dinoY); std::cout << "       ████████          ";
        Utility::gotoxy(dinoPos, 29 - gameState.dinoY); std::cout << "       ████████          ";
        Utility::gotoxy(dinoPos, 30 - gameState.dinoY);
    }

    if (ducking) {
       
        Utility::gotoxy(dinoPos, 21 - gameState.dinoY); std::cout << "                      ";  
        Utility::gotoxy(dinoPos, 22 - gameState.dinoY); std::cout << "                      ";  
        Utility::gotoxy(dinoPos, 23 - gameState.dinoY); std::cout << "                      ";  
        Utility::gotoxy(dinoPos, 24 - gameState.dinoY); std::cout << "                      ";  

        
        Utility::gotoxy(dinoPos, 21 - gameState.dinoY); std::cout << "                      ";  
        Utility::gotoxy(dinoPos, 25 - gameState.dinoY); std::cout << "             ████  ";
        Utility::gotoxy(dinoPos, 26 - gameState.dinoY); std::cout << "            ██░░██  ";
        Utility::gotoxy(dinoPos, 27 - gameState.dinoY); std::cout << "     █      ████   ";
        Utility::gotoxy(dinoPos, 28 - gameState.dinoY); std::cout << "      █   ██████   ";
        Utility::gotoxy(dinoPos, 29 - gameState.dinoY); std::cout << "       ████████        ";
      } else {
       if (jump == 1 || jump == 2) {
        std::cout << "     █    █        ";
        Utility::gotoxy(dinoPos, 31 - gameState.dinoY);
        std::cout << "     █    █        ";
    } else if (foot == 0) {
      
        Utility::gotoxy(dinoPos, 31 - gameState.dinoY);
        std::cout << "       █   █      ";
        foot = !foot;
    } else if (foot == 1) {
        std::cout << "      █    █     ";
        Utility::gotoxy(dinoPos, 31 - gameState.dinoY);
        std::cout << "    █       █  ";
        foot = !foot;
    }
    }

    Utility::gotoxy(dinoPos, 32 - gameState.dinoY);
    if (jump != 0) {
      
    
        std::cout << "                ";  
    }

    Sleep(gameState.speed);   
}

void Dino::selectDino() {
    system("cls");

    Utility::gotoxy(50, 6); 
    std::cout << "Select your Dino: (\033[1;32m1\033[0m, \033[1;33m2\033[0m, or \033[1;34m3\033[0m)";

    Utility::gotoxy(50, 7); 
    std::cout << "\033[1;32m1.\033[0m Dino Type 1";

    Utility::gotoxy(50, 8); 
    std::cout << "\033[1;33m2.\033[0m Dino Type 2";

    Utility::gotoxy(50, 9); 
    std::cout << "\033[1;34m3.\033[0m Dino Type 3";

    Utility::gotoxy(50, 11); 
    std::cout << "Your selection: ";

    char dinoChoice = getche();  

    if (dinoChoice == '1') {
        gameState.selectedDino = 1;  
    } else if (dinoChoice == '2') {
        gameState.selectedDino = 2;  
    } else if (dinoChoice == '3') {
        gameState.selectedDino = 3;  
    } else {
        gameState.selectedDino = 1;  
    }
}
