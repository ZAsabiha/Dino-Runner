#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <fstream> 



class Score {
public:

    Score();
    void loadHighScore();
    void saveHighScore();
    void displayScore(int currentScore);
    int getHighScore() const;
    void setHighScore(int newHighScore);
    void scoring();

private:
    int currentScore;
    int highScore;
    void gotoxy(int x, int y);
};

#endif // SCORE_H
