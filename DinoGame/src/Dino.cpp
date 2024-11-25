#include "Dino.h"

void Dino::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void moveDino(int jump = 0, bool ducking = false) {
    static int foot = 0;

    if (jump == 0)
        dinoY = 0;
    else if (jump == 2)
        dinoY--;
    else
        dinoY++;


    gotoxy(dinoPos, 21 - dinoY); cout << "                      ";
  
    if (selectedDino == 1) {

    gotoxy(dinoPos, 22 - dinoY); cout << "             █████  ";
    gotoxy(dinoPos, 23 - dinoY); cout << "            ███░░██";
    gotoxy(dinoPos, 24 - dinoY); cout << "           ██████   ";
    gotoxy(dinoPos, 25 - dinoY); cout << "  █          ███";
    gotoxy(dinoPos, 26 - dinoY); cout << "  ██         ███ ";
    gotoxy(dinoPos, 27 - dinoY); cout << "   ███     █████          ";
    gotoxy(dinoPos, 28 - dinoY); cout << "     ██████████          ";
    gotoxy(dinoPos, 29 - dinoY); cout << "    ██████████          ";
    gotoxy(dinoPos, 30 - dinoY);
    } else if (selectedDino == 2) {

    gotoxy(dinoPos, 22 - dinoY); cout << "              ███  ";
    gotoxy(dinoPos, 23 - dinoY); cout << "            ███░░██";
    gotoxy(dinoPos, 24 - dinoY); cout << "             █████   ";
    gotoxy(dinoPos, 25 - dinoY); cout << "  █           ██";
    gotoxy(dinoPos, 26 - dinoY); cout << "  ██          ██ ";
    gotoxy(dinoPos, 27 - dinoY); cout << "   ███        ██          ";
    gotoxy(dinoPos, 28 - dinoY); cout << "      █████████          ";
    gotoxy(dinoPos, 29 - dinoY); cout << "        ███████          ";
    gotoxy(dinoPos, 30 - dinoY);
    } else if (selectedDino == 3) {
        
    gotoxy(dinoPos, 22 - dinoY); cout << "             █████  ";
    gotoxy(dinoPos, 23 - dinoY); cout << "            ███░░██";
    gotoxy(dinoPos, 24 - dinoY); cout << "           ██████   ";
    gotoxy(dinoPos, 25 - dinoY); cout << "            ███";
    gotoxy(dinoPos, 26 - dinoY); cout << "       ████████ ";
    gotoxy(dinoPos, 27 - dinoY); cout << "       ████████          ";
    gotoxy(dinoPos, 28 - dinoY); cout << "       ████████          ";
    gotoxy(dinoPos, 29 - dinoY); cout << "       ████████          ";
    gotoxy(dinoPos, 30 - dinoY);
    }

    if (ducking) {
     
        gotoxy(dinoPos, 21 - dinoY); cout << "                      ";  
        gotoxy(dinoPos, 22 - dinoY); cout << "                      "; 
        gotoxy(dinoPos, 23 - dinoY); cout << "                      "; 
        gotoxy(dinoPos, 24 - dinoY); cout << "                      "; 

        // Draw the ducking position
        gotoxy(dinoPos, 21 - dinoY); cout << "                  
        gotoxy(dinoPos, 25 - dinoY); cout << "             ████  ";
        gotoxy(dinoPos, 26 - dinoY); cout << "            ██░░██  ";
        gotoxy(dinoPos, 27 - dinoY); cout << "     █      ████   ";
        gotoxy(dinoPos, 28 - dinoY); cout << "      █   ██████   ";
        gotoxy(dinoPos, 29 - dinoY); cout << "       ████████        ";
      } else {
       if (jump == 1 || jump == 2) {
        cout << "     █    █        ";
        gotoxy(2, 31 - dinoY);
        cout << "     █    █        ";
    } else if (foot == 0) {
      
        gotoxy(2, 31 - dinoY);
        cout << "       █   █      ";
        foot = !foot;
    } else if (foot == 1) {
        cout << "      █    █     ";
        gotoxy(2, 31 - dinoY);
        cout << "    █       █  ";
        foot = !foot;
    }
    }

    gotoxy(dinoPos, 32 - dinoY);
    if (jump == 0) {
       
    } else {
        cout << "                ";  
    }

    Sleep(speed);  
}
