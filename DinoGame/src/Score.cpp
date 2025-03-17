#include "Score.h"
#include <fstream> 
#include <iostream>
#include <conio.h> 
#include <windows.h>
#include "Utility.h"
int gameover=0;
Score::Score() : currentScore(0), highScore(0) {}

void Score::loadHighScore() {
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0; 
    }
}

void Score::saveHighScore() {
    std::ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
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
    std::cout << "\033[1;36mHIGH SCORE: \033[0m" << highScore;
}

int Score::getHighScore() const {
    return highScore;
}

void Score::setHighScore(int newHighScore) {
    highScore = newHighScore;
}


