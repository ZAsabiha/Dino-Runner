
#include "Score.h"
#include <fstream> 
#include <iostream>
#include <conio.h> 
#include <windows.h>
#include "Utility.h"
#include "GameLogic.h"
#include "Global.h"
int gameover=0;
Score::Score()  {}

void Score::loadHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> gameState.highScore;
        file.close();
    } else {
        gameState.highScore = 0; 
    }
}

void Score::saveHighScore() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << gameState.highScore;
        file.close();
    }
}
void Score :: scoring(){
    gameover = 0;
    Utility::gotoxy(3, 2);
std::cout << "\033[1;32mSCORE :\033[0m"; 
}

void Score::displayScore(int currentScore) {
    Utility::gotoxy(3, 2);
    std::cout << "\033[1;32mSCORE: \033[0m" << currentScore;
    
    
    Utility::gotoxy(3, 4);
    std::cout << "\033[1;36mHIGH SCORE: \033[0m" << gameState.highScore;
}

int Score::getHighScore() const {
    return gameState.highScore;
}

void Score::setHighScore(int newHighScore) {
    gameState.highScore = newHighScore;
}

