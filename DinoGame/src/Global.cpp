
#include "global.h"


Global gameState;


Global::Global() : 
    dinoY(0), 
    speed(20), 
    gameover(0), 
    currentScore(0), 
    highScore(0), 
    lives(3), 
    powerUpX(-1), 
    currentPowerUp(""),
    horizontalWeaponActive(false), 
    verticalWeaponActive(false), 
    horizontalMissileCount(0), 
    verticalMissileCount(0), 
    selectedDino(1)
{}
