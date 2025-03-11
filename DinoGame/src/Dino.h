#ifndef DINO_H
#define DINO_H

#include <iostream>
#include <windows.h>
#include "Utility.h"

class Dino {


public:
   
    void moveDino(int jump = 0, bool ducking = false);
    void selectDino();
};

#endif


