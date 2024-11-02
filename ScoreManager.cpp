#include <iostream>
#include <fstream>
#include <string>

class ScoreManager {
private:
    int currentScore;
    int highScore;
    std::string filename;

public:
    ScoreManager(const std::string& file) : filename(file), currentScore(0), highScore(0) {
        loadHighScore();
    }

    void resetScore() {
        currentScore = 0;
    }

    void incrementScore() {
        currentScore++;
    }

    int getCurrentScore() const {
        return currentScore;
    }

    int getHighScore() const {
        return highScore;
    }

    void checkAndSetHighScore() {
        if (currentScore > highScore) {
            highScore = currentScore;
            saveHighScore();
        }
    }

    void displayScores() const {
        std::cout << "Current Score: " << currentScore << std::endl;
        std::cout << "Highest Score: " << highScore << std::endl;
    }

private:
    void loadHighScore() {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> highScore;
            file.close();
        }
    }

    void saveHighScore() {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << highScore;
            file.close();
        }
    }
};

int main() {
    ScoreManager scoreManager("highscore.txt");

    scoreManager.incrementScore();
    scoreManager.displayScores();

    scoreManager.checkAndSetHighScore();
    scoreManager.displayScores();

    return 0;
}
