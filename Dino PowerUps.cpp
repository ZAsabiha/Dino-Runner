#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <fstream> 

#define dinoPos 2
#define hurdlePos 74

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int dinoY;
int speed = 40;
int gameover = 0;
int currentScore = 0;
int highScore = 0;
int lives = 3; 
int powerUpX = -1; 
char currentPowerUp = ' ';

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) size = 20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void loadHighScore() {
    ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highScore;
        file.close();
    } else {
        highScore = 0;
    }
}

void saveHighScore() {
    ofstream file("highscore.txt");
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

void init() {
    system("cls");
    gameover = 0;
    gotoxy(3, 2); cout << "SCORE : ";
    gotoxy(30, 2); cout << "LIVES: " << lives;
    for (int i = 0; i < 79; i++) {
        gotoxy(1 + i, 1); cout << "п";
        gotoxy(1 + i, 25); cout << "п";
    }
    loadHighScore();
}

void moveDino(int jump = 0) {
    static int foot = 0;

    if (jump == 0) dinoY = 0;
    else if (jump == 2) dinoY--;
    else dinoY++;

    gotoxy(dinoPos, 15 - dinoY); cout << "                 ";
    gotoxy(dinoPos, 16 - dinoY); cout << "        * * * * ";
    gotoxy(dinoPos, 17 - dinoY); cout << "       * * * * * ";
    gotoxy(dinoPos, 18 - dinoY); cout << "        * * * * ";
    gotoxy(dinoPos, 19 - dinoY); cout << "       *       * ";
    gotoxy(dinoPos, 20 - dinoY); cout << "        *     *  ";
    gotoxy(dinoPos, 21 - dinoY); cout << "         * * *   ";
    gotoxy(dinoPos, 22 - dinoY); cout << "          * *    ";
    Sleep(speed);
}

void drawHurdleAndPowerUp() {
    static int plantX = 0;


    if (plantX == 56 && dinoY < 3) {
        lives--;
        gotoxy(30, 2); cout << "LIVES: " << lives;

        if (lives == 0) {
            gameover = 1;
            gotoxy(36, 8); cout << "Game Over";
            gotoxy(36, 9); cout << "Your Score: " << currentScore;
            gotoxy(36, 10); cout << "Previous High Score: " << highScore;

            if (currentScore > highScore) {
                highScore = currentScore;
                saveHighScore();
                gotoxy(36, 11); cout << "New High Score!";
            }
            getch();
            return;
        }
    }

 
    gotoxy(hurdlePos - plantX, 20); cout << "| | ";
    gotoxy(hurdlePos - plantX, 21); cout << "| | ";
    gotoxy(hurdlePos - plantX, 22); cout << "|_| ";
    gotoxy(hurdlePos - plantX, 23); cout << " |  ";
    gotoxy(hurdlePos - plantX, 24); cout << " |  ";

  
    if (powerUpX == -1 && rand() % 50 == 0) {
        powerUpX = hurdlePos;
        
        
        int randomPowerUp = rand() % 3;
        if (randomPowerUp == 0) currentPowerUp = 'P'; 
        else if (randomPowerUp == 1) currentPowerUp = 'I'; 
        else currentPowerUp = 'S'; 
    }

    
    if (powerUpX != -1) {
        gotoxy(powerUpX, 19); cout << " " << currentPowerUp << " ";
        powerUpX--;

        
        if (powerUpX == dinoPos && dinoY < 3) {
            if (currentPowerUp == 'P' && lives < 3) {
                lives++;
                gotoxy(30, 2); cout << "LIVES: " << lives;
            } else if (currentPowerUp == 'I') {
                currentScore += 10; 
                gotoxy(11, 2); cout << currentScore;
            } else if (currentPowerUp == 'S') {
                speed -= 5; 
                if (speed < 20) speed = 20;
            }
            powerUpX = -1; 
        }

        if (powerUpX < 0) powerUpX = -1;
    }

    plantX++;
    if (plantX == 73) {
        plantX = 0;
        currentScore++;
        gotoxy(11, 2); cout << "     ";
        gotoxy(11, 2); cout << currentScore;
        if (speed > 20) speed--;
    }
}

void play() {
    system("cls");
    init();
    currentScore = 0;
    lives = 3;
    char ch;
    int i;

    
    while (true) {
        while (!kbhit()) {
            if (gameover == 1) return;
            moveDino();
            drawHurdleAndPowerUp();
        }
        ch = getch();

        
        if (ch == 32) {
            i = 0;
            
            while (i < 12) {
                moveDino(1);
                drawHurdleAndPowerUp();
                i++;
            }
           
            while (i > 0) {
                moveDino(2);
                drawHurdleAndPowerUp();
                i--;
            }
        }
        
        else if (ch == 'p' || ch == 'P') getch();
       
        else if (ch == 27) break;
    }
}

int main() {
    setcursor(0, 0);
    srand(time(0));

    do {
        system("cls");
        gotoxy(10, 5); cout << " -------------------------- ";
        gotoxy(10, 6); cout << " |        DINO RUN        | ";
        gotoxy(10, 7); cout << " -------------------------- ";
        gotoxy(10, 9); cout << "1. Start Game";
        gotoxy(10, 10); cout << "2. Quit";
        gotoxy(10, 12); cout << "Select option: ";
        char op = getche();

        if (op == '1') play();
        else if (op == '2') exit(0);
    } while (1);

    return 0;
}
    