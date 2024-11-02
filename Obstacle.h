#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
private:
    int obstacleX;
    int score;
    int obstacleType;
    int speed;

public:
    Obstacle(int initialSpeed);
    void drawObstacles(int dinoY);
    void resetObstacle();
    int getScore() const;
    int getSpeed() const;
    void setSpeed(int newSpeed);
    bool checkCollision(int dinoY) const;
};

#endif // OBSTACLE_H

