#include <iostream>
#include <conio.h>  
#include <windows.h>

using namespace std;


void play();
void instructions();
void selectDino();
void displayGameTitle();
void setcursor(int x, int y);
void gotoxy(int x, int y);


int gameover = 0;


void clearScreen() {
    system("cls");
}

void play() {
   cout<<"Game playing .... just for test";
}

void instructions() {
    system("cls");
    cout << "Instructions";
    cout << "\n----------------";
    cout << "\n1. Avoid hurdles by jumping";
    cout << "\n2. Press 'Spacebar' to jump";
    cout << "\n3. Press 'Esc' to exit";
    cout << "\nPress any key to go back to menu.";
    getch();
}

void selectDino() {
    system("cls");
    cout << "Select your Dino: (\033[1;32m1\033[0m, \033[1;33m2\033[0m, or \033[1;34m3\033[0m)\n";
    cout << "\033[1;32m1.\033[0m Dino Type 1\n";
    cout << "\033[1;33m2.\033[0m Dino Type 2\n";
    cout << "\033[1;34m3.\033[0m Dino Type 3\n";
    cout << "Your selection: ";
    int selectedDino;
    cin >> selectedDino;

    if (selectedDino < 1 || selectedDino > 3) {
        selectedDino = 1; 
    }
}

void displayGameTitle() {
   
    gotoxy(55, 3);  cout << "\033[1;31m" << "  _____  _               _____             \n";
    gotoxy(55, 4);  cout << "\033[1;33m" << " |  __ \\(_)             |  __ \\            \n";
    gotoxy(55, 5);  cout << "\033[1;32m" << " | |  | |_ _ __   ___   | |__) |   _ _ __  \n";
    gotoxy(55, 6);  cout << "\033[1;34m" << " | |  | | | '_ \\ / _ \\  |  _  / | | | '_ \\ \n";
    gotoxy(55, 7);  cout << "\033[1;35m" << " | |__| | | | | | (_) | | | \\ \\ |_| | | | |\n";
    gotoxy(55, 8);  cout << "\033[1;36m" << " |_____/|_|_| |_|\\___/  |_|  \\_\\__,_|_| |_|\n";
    cout << "\033[0m"; 
}

void mainMenu() {
    while (true) {
        clearScreen(); 
        displayGameTitle();
        gotoxy(55, 15);  cout << "\033[1;31m" << "1. Play" << "\033[0m"; 
        gotoxy(55, 19); cout << "\033[1;33m" << "2. Instructions" << "\033[0m"; 
        gotoxy(55, 22); cout << "\033[1;32m" << "3. Select Dino" << "\033[0m"; 
        gotoxy(55, 25); cout << "\033[1;34m" << "4. Exit" << "\033[0m"; 
        gotoxy(55, 28); cout << "Select an option: ";

        char option;
        cin >> option;

        switch (option) {
            case '1':
                play();
                break;
            case '2':
                instructions();
                break;
            case '3':
                selectDino();
                break;
            case '4':
                exit(0);
                break;
            default:
                cout << "Invalid option! Please try again.";
                getch();
                break;
        }
    }
}

int main() {
    setcursor(0, 0); 
    mainMenu(); 
    return 0;
}
