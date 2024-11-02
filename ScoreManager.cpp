#include "ScoreManager.h"
#include <fstream>

ScoreManager::ScoreManager(const std::string& file) : filename(file), currentScore(0), highScore(0) {
    loadHighScore();
}

void ScoreManager::resetScore() {
    currentScore = 0;
}

void ScoreManager::incrementScore() {
    currentScore++;
}

int ScoreManager::getCurrentScore() const {
    return currentScore;
}

int ScoreManager::getHighScore() const {
    return highScore;
}

void ScoreManager::checkAndSetHighScore() {
    if (currentScore > highScore) {
        highScore = currentScore;
        saveHighScore();
    }
}

void ScoreManager::loadHighScore() {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
}

void ScoreManager::saveHighScore() {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

int main() {
    ScoreManager scoreManager("highscore.txt");

   
    scoreManager.incrementScore();  
    int previousHighScore = scoreManager.getHighScore();  


    scoreManager.checkAndSetHighScore();

    
    printf("\nGame Over!\n");
    printf("Your Score: %d\n", scoreManager.getCurrentScore());
    printf("Previous Highest Score: %d\n", previousHighScore);
    printf("New Highest Score: %d\n", scoreManager.getHighScore());

    return 0;
}

