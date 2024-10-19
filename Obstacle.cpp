#include "Obstacle.h"
#include <iostream>
#include <windows.h>
#include <cstdlib> // For rand()
using namespace std;

#define hurdlePos 74

extern void gotoxy(int x, int y); // Assuming gotoxy is defined elsewhere
extern int gameover;

Obstacle::Obstacle(int initialSpeed) {
    obstacleX = 0;
    score = 0;
    obstacleType = rand() % 3; // Randomly selects the obstacle type (0, 1, or 2)
    speed = initialSpeed;
}

void Obstacle::drawObstacles(int dinoY) {
    int obstacleHeight = (obstacleType == 1) ? 16 : 20; // Birds appear at a higher height

    // Collision detection
    if (obstacleX == 56 && dinoY < (obstacleType == 1 ? 5 : 3)) {
        score = 0;
        speed = 40;
        gotoxy(36, 8); cout << "Game Over";
        getch();
        gameover = 1;
    }

    // Clear the previous obstacle
    gotoxy(hurdlePos - obstacleX, obstacleHeight); cout << "    ";
    gotoxy(hurdlePos - obstacleX, obstacleHeight + 1); cout << "    ";
    gotoxy(hurdlePos - obstacleX, obstacleHeight + 2); cout << "    ";
    gotoxy(hurdlePos - obstacleX, obstacleHeight + 3); cout << "    ";

    // Draw new obstacle based on the type
    if (obstacleType == 0) {
        // Cactus
        gotoxy(hurdlePos - obstacleX, 20); cout << " | | ";
        gotoxy(hurdlePos - obstacleX, 21); cout << " | | ";
        gotoxy(hurdlePos - obstacleX, 22); cout << "|_| ";
        gotoxy(hurdlePos - obstacleX, 23); cout << " |  ";
        gotoxy(hurdlePos - obstacleX, 24); cout << " |  ";
    } else if (obstacleType == 1) {
        // Bird
        gotoxy(hurdlePos - obstacleX, 16); cout << "  __ ";
        gotoxy(hurdlePos - obstacleX, 17); cout << "<(o )___ ";
        gotoxy(hurdlePos - obstacleX, 18); cout << " (     )";
        gotoxy(hurdlePos - obstacleX, 19); cout << "  `---' ";
    } else if (obstacleType == 2) {
        // Rock
        gotoxy(hurdlePos - obstacleX, 20); cout << " /\\_/\\ ";
        gotoxy(hurdlePos - obstacleX, 21); cout << "( o o )";
        gotoxy(hurdlePos - obstacleX, 22); cout << " > ^ < ";
    }

    obstacleX++;

    if (obstacleX == 73) {
        obstacleX = 0;
        score++;
        gotoxy(11, 2); cout << "     ";
        gotoxy(11, 2); cout << score;
        if (speed > 20)
            speed--;

        // Randomize the new obstacle type for the next iteration
        obstacleType = rand() % 3;
    }
}

void Obstacle::resetObstacle() {
    obstacleX = 0;
    obstacleType = rand() % 3;
}

int Obstacle::getScore() const {
    return score;
}

int Obstacle::getSpeed() const {
    return speed;
}

void Obstacle::setSpeed(int newSpeed) {
    speed = newSpeed;
}

bool Obstacle::checkCollision(int dinoY) const {
    int obstacleHeight = (obstacleType == 1) ? 16 : 20; // Birds appear at a higher height
    return (obstacleX == 56 && dinoY < (obstacleType == 1 ? 5 : 3));
}


