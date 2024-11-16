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
    system("cls");
    char ch;
    int jumpHeight;
    int missileX = 15, missileY = -1;  
    bool missileActive = false;        
    bool isVertical = false;           
    bool isDucking = false;           

    while (true) {
        while (!kbhit()) {
            if (gameover == 1) {
                return;
            }

            
            score();
            moveDino(0, isDucking);  
            drawHurdle(missileX, missileY, missileActive, isDucking);  
            drawClouds();

            
            if (missileActive) {
                moveProjectile(missileX, missileY, missileActive, isVertical); 
                drawProjectile(missileX, missileY, missileActive, isVertical);
            }

            Sleep(100);  
        }

        ch = getch();

     
        if (ch == 's' || ch == 'S' && !isDucking) {  
            jumpHeight = 0;
            while (jumpHeight < 12) {
                moveDino(1, isDucking);  
                drawHurdle(missileX, missileY, missileActive, isDucking);
                jumpHeight++;
            }
            while (jumpHeight > 0) {
                moveDino(2, isDucking);  
                drawHurdle(missileX, missileY, missileActive, isDucking);
                jumpHeight--;
            }
        } 

        
        else if (ch == 'f' || ch == 'F') {  
            if (!missileActive) {  
                isVertical = false; 
                missileY = 29; 
                fireProjectile(missileX, missileY, missileActive, isVertical);  
            }
        }

        
        else if (ch == 'v' || ch == 'V') {  
            if (!missileActive) {  
                isVertical = true; 
                missileY = 21; 
                fireProjectile(missileX, missileY, missileActive, isVertical);  
            }
        }

        
        else if (ch == 'd' || ch == 'D') {  
            isDucking = true;  
        }

        else if (ch == 'w' || ch == 'W') {  
            isDucking = false;  
        }

     
        else if (ch == 'p' || ch == 'P') {  
            getch();  
        }

       
        else if (ch == 27) {  
            break;
        }
    }
}


void instructions() {
    system("cls");

    gotoxy(50, 6);
    cout << "\033[36m ___           _                   _   _                 \033[0m";
    gotoxy(50, 7);
    cout << "\033[32m|_ _|_ __  ___| |_ _ __ _   _  ___| |_(_) ___  _ __  ___ \033[0m";
    gotoxy(50, 8);
    cout << "\033[33m | || '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __|\033[0m";
    gotoxy(50, 9);
    cout << "\033[35m | || | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\ \033[0m";
    gotoxy(50, 10);
    cout << "\033[31m|___|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/\033[0m";
    gotoxy(50, 11);
    cout << "\033[34m---------------------------------------------------------\033[0m";

 
     gotoxy(50, 15)
    cout << "\033[31m1. Avoid hurdles by jumping\033[0m"; 
    gotoxy(50, 18);
    cout << "\033[32m2. Press 'Spacebar' to jump\033[0m"; 
    gotoxy(50, 21);
    cout << "\033[34m3. Press 'Esc' to exit\033[0m";      
    gotoxy(50, 24);
    cout << "\033[33m4. Collect coins for extra points\033[0m"; 


    gotoxy(90, 35);
    cout << "\033[36mPress any key to go back to the menu.\033[0m"; 
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
