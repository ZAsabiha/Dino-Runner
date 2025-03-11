
#include <iostream> 
#include <conio.h>
#include <fstream> 
#include <windows.h>
#include<stdlib.h>
#include <time.h>
#include "GameOver.h"
#include "Utility.h"
#include "Global.h"

      




void GameOver::displayGameOver() {
    Utility::clearScreen();


    Utility::gotoxy(50, 6);
    std::cout << "\033[1;31m   ____                         ___                  \033[0m";
    Utility::gotoxy(50, 7);
    std::cout << "\033[1;31m  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __  \033[0m";
    Utility::gotoxy(50, 8);
    std::cout << "\033[1;31m | |  _ / _ | '_  _ \\ / _ \\ | | | \\ \\ / / _ \\ '__| \033[0m";
    Utility::gotoxy(50, 9);
    std::cout << "\033[1;31m | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |    \033[0m";
    Utility::gotoxy(50, 10);
    std::cout << "\033[1;31m  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|    \033[0m";

    Utility::gotoxy(50, 20);
    std::cout << "\033[1;32mYour Score: \033[0m" << gameState.currentScore;
    Utility::gotoxy(50, 24);
    std::cout << "\033[1;36mPrevious High Score: \033[0m" << gameState.highScore;

    if (gameState.currentScore > gameState.highScore) {
        gameState.highScore = gameState.currentScore;
        gameState.score.saveHighScore();
        Utility::gotoxy(50, 27);
        std::cout << "\033[1;33mNew High Score!\033[0m";
    } else {
        Utility::gotoxy(50, 28);
        std::cout << "\033[1;33mTry Again to Beat the High Score!\033[0m";
    }

    Utility::gotoxy(90, 35);
    std::cout << "\033[1;33mPress any key to continue...\033[0m";

    getch();
}
