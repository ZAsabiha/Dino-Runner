#include "ScoreManager.h"
#include <iostream>
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

void ScoreManager::displayScores() const {
    std::cout << "Current Score: " << currentScore << std::endl;
    std::cout << "Highest Score: " << highScore << std::endl;
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
