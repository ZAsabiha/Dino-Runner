#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
private:
    int currentScore;
    int highScore;
    std::string filename;

public:
    ScoreManager(const std::string& file);
    void resetScore();
    void incrementScore();
    int getCurrentScore() const;
    int getHighScore() const;
    void checkAndSetHighScore();
    void displayScores() const;

private:
    void loadHighScore();
    void saveHighScore();
};


