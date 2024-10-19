#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "Obstacle.h"

#define dinoPos 2

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int dinoY;
int gameover = 0;
int speed = 40;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) {
        size = 20;
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void moveDino(int jump = 0) {
    // (Code for dino movement remains the same)
}

void drawClouds() {
    // (Code for drawing clouds remains the same)
}

void play() {
    system("cls");
    char ch;
    int i;
    gameover = 0;
    Obstacle obstacle(speed); // Initialize Obstacle with the current speed

    gotoxy(3, 2); cout << "SCORE : ";
    while (true) {
        while (!kbhit()) {
            if (gameover == 1) {
                return;
            }
            moveDino();
            obstacle.drawObstacles(dinoY);
            drawClouds();
        }
        ch = getch();
        if (ch == 32) {
            i = 0;
            while (i < 12) {
                moveDino(1);
                obstacle.drawObstacles(dinoY);
                drawClouds();
                i++;
            }
            while (i > 0) {
                moveDino(2);
                obstacle.drawObstacles(dinoY);
                drawClouds();
                i--;
            }
        } else if (ch == 'p' || ch == 'P')
            getch();
        else if (ch == 27)
            break;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    setcursor(0, 0);
    play();
    return 0;
}



