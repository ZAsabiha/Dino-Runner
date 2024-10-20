#include "Dino.h"

void Dino::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Dino::setCursor(bool visible, DWORD size) {
    if (size == 0) size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &lpCursor);
}

void Dino::move(int jump) {
    static int foot = 0;

    if (jump == 0)
        dinoY = 0;
    else if (jump == 2)
        dinoY--;
    else
        dinoY++;

    gotoxy(dinoPos, 15 - dinoY); std::cout << "                 ";
    drawDino(jump);

    gotoxy(dinoPos, 28 - dinoY);
    std::cout << (jump == 0 ? "*****************" : "                ");
    Sleep(speed);
}

void Dino::drawDino(int jump) {
    gotoxy(dinoPos, 16 - dinoY); std::cout << "               __";
    gotoxy(dinoPos, 17 - dinoY); std::cout << "              / _)"; 
    gotoxy(dinoPos, 18 - dinoY); std::cout << "     _/\\/\\/\\_/ /"; 
    gotoxy(dinoPos, 19 - dinoY); std::cout << "   _|         /"; 
    gotoxy(dinoPos, 20 - dinoY); std::cout << " _|  (  | (  |"; 
    gotoxy(dinoPos, 21 - dinoY); std::cout << "/__.-'|_|--|_|"; 

    gotoxy(dinoPos, 22 - dinoY); std::cout << "        *       * ";
    gotoxy(dinoPos, 23 - dinoY); std::cout << "         *     *  ";
    gotoxy(dinoPos, 24 - dinoY); std::cout << "          * * *   ";
    gotoxy(dinoPos, 25 - dinoY); std::cout << "           * *    ";
    gotoxy(dinoPos, 26 - dinoY);
}

