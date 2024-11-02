#include <iostream>
#include <conio.h> 
#include <windows.h> 

using namespace std;

class GameOverScreen {
public:
   void displayGameOver() {
    clearScreen(); 

   
    gotoxy(50, 6);
    cout << "\033[1;31m   ____                         ___                  \033[0m";
    gotoxy(50, 7);
    cout << "\033[1;31m  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __  \033[0m";
    gotoxy(50, 8);
    cout << "\033[1;31m | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__| \033[0m";
    gotoxy(50, 9);
    cout << "\033[1;31m | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |    \033[0m";
    gotoxy(50, 10);
    cout << "\033[1;31m  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|    \033[0m";

  "
    gotoxy(90, 35); 
    cout << "\033[1;33mPress any key to continue...\033[0m"; // Yellow color

    getch(); 
}

private:
    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x; 
        coord.Y = y; 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void clearScreen() {
        system("CLS"); 
    }
};



