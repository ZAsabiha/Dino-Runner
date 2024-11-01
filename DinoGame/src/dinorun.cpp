#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int dinoPos = 10; 
int dinoY = 0;    
int speed = 100;  


void gotoxy(int x, int y) {
    COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void moveDino(int jump = 0) {
    static int foot = 0;

 
    if (jump == 0)
        dinoY = 0;
    else if (jump == 2)
        dinoY--;
    else
        dinoY++;


    gotoxy(dinoPos, 15 - dinoY); cout << "                      ";
    gotoxy(dinoPos, 16 - dinoY); cout << "                 ██████████████  ";
    gotoxy(dinoPos, 17 - dinoY); cout << "                      ████░░████████████";
    gotoxy(dinoPos, 18 - dinoY); cout << "                      ██████████████████";
    gotoxy(dinoPos, 19 - dinoY); cout << "                      ██████████████████";
    gotoxy(dinoPos, 20 - dinoY); cout << "                      ██████████████████";
    gotoxy(dinoPos, 21 - dinoY); cout << "                      ████████          ";
    gotoxy(dinoPos, 22 - dinoY); cout << "                      ██████████████░░  ";
    gotoxy(dinoPos, 23 - dinoY); cout << "                      ██████            ";
    gotoxy(dinoPos, 24 - dinoY); cout << "  █              ██████████            ";
    gotoxy(dinoPos, 25 - dinoY); cout << "  ██        ▒▒▒▒██████████▒▒▒▒        ";
    gotoxy(dinoPos, 26 - dinoY); cout << "  ███   ██████████████  ▒▒        ";
    gotoxy(dinoPos, 27 - dinoY); cout << "  ██████▒▒▒▒█████            ";
    gotoxy(dinoPos, 28 - dinoY); cout << "  ███████████████            ";
    
   
    gotoxy(dinoPos, 29 - dinoY);
    if (jump == 1 || jump == 2) {
        cout << "    ██    ██       ";
        gotoxy(dinoPos, 30 - dinoY);
        cout << "    ████  ████     ";
    } 
    else if (foot == 0) {
        cout << "    ████    ████   ";
        gotoxy(dinoPos, 30 - dinoY);
        cout << "        ████       ";
        foot = 1;
    } else {
        cout << "    ████    ████   ";
        gotoxy(dinoPos, 30 - dinoY);
        cout << "    ████    ████   ";
        foot = 0;
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int jump = 0;
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == ' ') { 
                jump = 1;
            }
        }

        moveDino(jump);

        
        if (jump == 1) {
            if (dinoY < 5) jump = 2;
            else jump = 0;           
        } else if (jump == 2) {
            if (dinoY == 0) jump = 0;
        }

        Sleep(speed);
    }

    return 0;
}
