#include <iostream>
#include <conio.h> 
#include <windows.h> 

using namespace std;

class GameOverScreen {
public:
    void display() {
        clearScreen(); 

        gotoxy(30, 10); 
        cout << "\033[1;31m" << "   _____                                 ____                        \n";
        gotoxy(30, 11); cout << "  / ____|                               / __ \\                       \n";
        gotoxy(30, 12); cout << " | |  __    __ _   _ __ ___     ___    | |  | | __   __   ___   _ __ \n";
        gotoxy(30, 13); cout << " | | |_ |  / _` | | '_ ` _ \\   / _ \\   | |  | | \\ \\ / /  / _ \\ | '__|\n";
        gotoxy(30, 14); cout << " | |__| | | (_| | | | | | | | |  __/   | |__| |  \\ V /  |  __/ | |   \n";
        gotoxy(30, 15); cout << "  \\_____|  \\__,_| |_| |_| |_|  \\___|    \\____/    \\_/    \\___| |_|   \n";

        gotoxy(60, 30);
        cout << "\033[1;33m" << "Press any key to continue..." << "\033[0m"; // Yellow color

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



