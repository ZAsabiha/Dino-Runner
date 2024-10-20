#ifndef DINO_H
#define DINO_H

#include <iostream>
#include <windows.h>
#include <conio.h>

class Dino {
public:
    Dino() : dinoY(0), speed(40) {}
    void move(int jump = 0);
    void gotoxy(int x, int y);
    void setCursor(bool visible, DWORD size);

private:
    int dinoY;
    int speed;
    const int dinoPos = 2;

    void drawDino(int jump);
};

#endif 