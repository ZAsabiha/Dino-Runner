
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <string>

class GameLogic {
    public:
    
    
; 
    void drawHurdle(int missileX, int missileY, bool &missileActive, bool isDucking);
    void fireProjectile(int &missileX, int &missileY, bool &missileActive, bool isVertical);
    void moveProjectile(int &missileX, int &missileY, bool &missileActive, bool isVertical);
    void drawProjectile(int missileX, int missileY, bool missileActive, bool isVertical);
};

#endif 

