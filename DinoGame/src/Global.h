
#ifndef GLOBAL_H
#define GLOBAL_H

#include "Score.h"
#include "UI.h"
#include "Dino.h"
#include "GameControl.h"
#include "Shop.h"
#include "GameLogic.h"
#include <string>
#define dinoPos 2
#define hurdlePos 74
class Global {
public:
 
    int dinoY;
    int speed;
    int gameover;
    int currentScore;
    int highScore;
    int lives;
    int powerUpX;
    std::string currentPowerUp;


    bool horizontalWeaponActive;
    bool verticalWeaponActive;
    int horizontalMissileCount;
    int verticalMissileCount;


    int selectedDino;

   
    Score score;
    UI ui;
    Dino dino;
    GameControl gc;
    Shop shop;
    GameLogic gl;

    Global();
};

extern Global gameState; 

#endif 
