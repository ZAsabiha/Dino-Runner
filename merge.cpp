#include <iostream> 
#include <conio.h>
#include <fstream> 
#include <windows.h>
#include<stdlib.h>
#include <time.h>

#define dinoPos 2
#define hurdlePos 74

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int dinoY;
int speed = 20;
int gameover = 0;
int currentScore = 0;
int highScore = 0;
int lives = 3; 
int powerUpX = -1; 
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcursor(bool visible, DWORD size){
    if (size == 0) {
        size = 20; 
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}



int selectedDino = 1; 
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

void moveDino(int jump = 0) {
    static int foot = 0;

 
    if (jump == 0)
        dinoY = 0;
    else if (jump == 2)
        dinoY--;
    else
        dinoY++;



    gotoxy(dinoPos, 21 - dinoY); cout << "                      ";
    gotoxy(dinoPos, 22 - dinoY); cout << "             █████  ";
    gotoxy(dinoPos, 23 - dinoY); cout << "            ███░░██";
    gotoxy(dinoPos, 24 - dinoY); cout << "           ██████   ";
    gotoxy(dinoPos, 25 - dinoY); cout << "  █          ███";
    gotoxy(dinoPos, 26 - dinoY); cout << "  ██         ███ ";
    gotoxy(dinoPos, 27 - dinoY); cout << "   ███     █████          ";
    gotoxy(dinoPos, 28 - dinoY); cout << "     ██████████          ";
    gotoxy(dinoPos, 29 - dinoY); cout << "    ██████████          ";
    gotoxy(dinoPos, 30 - dinoY);



if (jump == 1 || jump == 2) {
        cout << "     █  █        ";
        gotoxy(2, 31 - dinoY);
        cout << "     █  █        ";
    } else if (foot == 0) {
      
        gotoxy(2, 31 - dinoY);
        cout << "       █  █      ";
        foot = !foot;
    } else if (foot == 1) {
        cout << "      █  █  █     ";
        gotoxy(2, 31 - dinoY);
        cout << "           █  █  ";
        foot = !foot;
    }

    gotoxy(2, 32 - dinoY);
    if (jump == 0) {
        
    } else {
        cout << "                ";
    }
    Sleep(speed);
}

void clearScreen() {

COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    DWORD consoleSize = screen.dwSize.X * screen.dwSize.Y;

    FillConsoleOutputCharacterA(console, ' ', consoleSize, topLeft, &written);

 
    FillConsoleOutputAttribute(console, screen.wAttributes, consoleSize, topLeft, &written);

    SetConsoleCursorPosition(console, topLeft);

}


void displayGameOver() {
    clearScreen();

    
    gotoxy(50, 6);
    cout << "\033[1;31m   ____                         ___                  \033[0m";
    gotoxy(50, 7);
    cout << "\033[1;31m  / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __  \033[0m";
    gotoxy(50, 8);
    cout << "\033[1;31m | |  _ / _ | '_  _ \\ / _ \\ | | | \\ \\ / / _ \\ '__| \033[0m";
    gotoxy(50, 9);
    cout << "\033[1;31m | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |    \033[0m";
    gotoxy(50, 10);
    cout << "\033[1;31m  \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|    \033[0m";

  
    gotoxy(50, 20); 
    cout << "\033[1;32mYour Score: \033[0m" << currentScore;  
    gotoxy(50, 24);
    cout << "\033[1;36mPrevious High Score: \033[0m" << highScore;  

   
    if (currentScore > highScore) {
        highScore = currentScore;
        saveHighScore();  
        gotoxy(50, 27); 
        cout << "\033[1;33mNew High Score!\033[0m";  
    } else {
        gotoxy(50, 28);
        cout << "\033[1;33mTry Again to Beat the High Score!\033[0m";  
    }

   
    gotoxy(90, 35); 
    cout << "\033[1;33mPress any key to continue...\033[0m";  

    getch();
}

void drawHurdle(int missileX, int missileY, bool &missileActive, bool isDucking) {
    
    static int plantX = 0;
    static int obstacleType = rand() % 3;
    static int score = 0;

    int dinoHeight = isDucking ? 2 : 4;
    int dinoHitboxY = isDucking ? 29 : 22;
    int hurdleX = hurdlePos - plantX;

   
    if(!isDucking){
    if ( plantX == 56 && dinoY < dinoHeight) {
        lives--;
        gotoxy(40, 2);
        if (lives == 3) {
            cout << "\033[1;31mLIVES: \033[1;32m" << lives << "\033[0m";
        } else if (lives == 2) {
            cout << "\033[1;31mLIVES: \033[1;33m" << lives << "\033[0m";
        } else if (lives == 1) {
            cout << "\033[1;31mLIVES: \033[1;31m" << lives << "\033[0m";
        }

        if (lives == 0) {
            gameover = 1;
            displayGameOver();
            getch();
            return;
        }
    }
    }
   
   if (missileActive) {
        if (!isDucking) {
            
            if (missileX >= hurdleX && missileX <= hurdleX + 3 && missileY >= 26 && missileY <= 31) {
                missileActive = false;
                plantX = 0;  
                score++;  
                currentScore = score;

              
                for (int i = 26; i <= 31; i++) {
                    gotoxy(hurdleX, i);
                    cout << "      ";
                }

               
                gotoxy(11, 2);
                cout << "     ";
                gotoxy(11, 2);
                cout << score;

               
                if (speed > 30) {
                    speed--;
                }

              
                obstacleType = rand() % 3;
                return;
            }
        
            
            if (missileX >= hurdleX && missileX <= hurdleX + 15 && missileY >= 20 && missileY <= 23) {
                missileActive = false;
                plantX = 0;  
                score++;  
                currentScore = score;

                
                for (int i = 20; i <= 23; i++) {
                    gotoxy(hurdleX, i);
                    cout << "         ";
                }

               
                gotoxy(11, 2);
                cout << "     ";
                gotoxy(11, 2);
                cout << score;

                
                if (speed > 30) {
                    speed--;
                }

               
                obstacleType = rand() % 3;
                return;
            }
        }
    }

     switch (obstacleType) {
        case 0: 
            gotoxy(hurdleX+1, 26); cout << "      ";
            gotoxy(hurdleX+1, 27); cout << "      ";
            gotoxy(hurdleX+1, 28); cout << "      ";
            gotoxy(hurdleX+1, 29); cout << "      ";
            gotoxy(hurdleX+1, 30); cout << "      ";
            gotoxy(hurdleX+1, 31); cout << "      ";
            break;
        case 1: 
            gotoxy(hurdleX+1, 29); cout << "      ";
            gotoxy(hurdleX+1, 30); cout << "      ";
            gotoxy(hurdleX+1, 31); cout << "      ";
            break;
        case 2: 
            gotoxy(hurdleX+1, 20); cout << "         ";
            gotoxy(hurdleX+1, 21); cout << "         ";
            gotoxy(hurdleX+1, 22); cout << "         ";
            gotoxy(hurdleX+1, 23); cout << "         ";
            break;
    }

   
    switch (obstacleType) {
        case 0: 
            gotoxy(hurdleX, 26); cout << "\033[1;31m█  █  \033[0m";
            gotoxy(hurdleX, 27); cout << "\033[1;31m█  █  \033[0m";
            gotoxy(hurdleX, 28); cout << "\033[1;31m████  \033[0m";
            gotoxy(hurdleX, 29); cout << "\033[1;31m  █   \033[0m";
            gotoxy(hurdleX, 30); cout << "\033[1;31m  █   \033[0m";
            gotoxy(hurdleX, 31); cout << "\033[1;31m  █   \033[0m";
            break;
        case 1:
            gotoxy(hurdleX, 29); cout << "\033[1;34m███   \033[0m";
            gotoxy(hurdleX, 30); cout << "\033[1;34m████  \033[0m";
            gotoxy(hurdleX, 31); cout << "\033[1;34m ███  \033[0m";
            break;
        case 2: 
            gotoxy(hurdleX, 21); cout << "\033[1;33m █████   \033[0m";
            gotoxy(hurdleX, 22); cout << "\033[1;33m██    ██ \033[0m";
            gotoxy(hurdleX, 23); cout << "\033[1;33m  ████    \033[0m";
            break;
    }

    
     if (powerUpX == -1 && rand() % 50 == 0) {
        powerUpX = hurdlePos;
        
        
        int randomPowerUp = rand() % 3;
        if (randomPowerUp == 0) currentPowerUp = "❤️"; 
        else if (randomPowerUp == 1) currentPowerUp = "👌"; 
        else currentPowerUp = "👍"; 
    }

    
    if (powerUpX != -1) {
        gotoxy(powerUpX, 19); cout << " " << currentPowerUp << " ";
        powerUpX--;

        
        if (powerUpX == dinoPos && dinoY < dinoHeight) {
            if (currentPowerUp == "❤️" && lives < 3) {
                lives++;
                gotoxy(40, 2);
                if(lives == 3) {
        cout << "\033[1;31mLIVES: \033[1;32m" << lives << "\033[0m";
    } else if(lives == 2) {
        cout << "\033[1;31mLIVES: \033[1;33m" << lives << "\033[0m";
    } else if(lives == 1) {
        cout << "\033[1;31mLIVES: \033[1;31m" << lives << "\033[0m";
    }
            } else if (currentPowerUp == "👌") {
                currentScore += 10; 
                gotoxy(11, 2); cout << currentScore;
            } else if (currentPowerUp == "👍") {
                speed += 5; 
                if (speed < 20) speed = 20;
            }
            powerUpX = -1; 
        }

        if (powerUpX < 0) powerUpX = -1;
    }



    plantX++;
    if (plantX == 73) {
        plantX = 0;
        score++;
        currentScore = score;

        gotoxy(11, 2);
        cout << "     ";
        gotoxy(11, 2);
        cout << score;

        if (speed > 30) {
            speed--;
        }

        obstacleType = rand() % 3;
    }
}




void drawClouds() {

    gotoxy(5, 5); cout << "\033[1;35m  _(  )_( )_  \033[0m"; 
    gotoxy(5, 6); cout << "\033[1;35m (_   _    _) \033[0m"; 
    gotoxy(5, 7); cout << "\033[1;35m   (_) (__)   \033[0m"; 

    gotoxy(50, 5); cout << "\033[1;35m  _(  )_( )_  \033[0m"; 
    gotoxy(50, 6); cout << "\033[1;35m (_   _    _) \033[0m"; 
    gotoxy(50, 7); cout << "\033[1;35m   (_) (__)   \033[0m"; 

    gotoxy(75, 5); cout << "\033[1;35m  _(  )_( )_  \033[0m"; 
    gotoxy(75, 6); cout << "\033[1;35m (_   _    _) \033[0m"; 
    gotoxy(75, 7); cout << "\033[1;35m   (_) (__)   \033[0m"; 
}
void shopMenu() {
    while (true) {
        system("cls");
        gotoxy(55, 10); cout << "\033[1;36mWelcome to the Shop!\033[0m";
        gotoxy(55, 13); cout << "Your Score: " << currentScore;
        gotoxy(55, 15); cout << "\033[1;31m1. Buy Extra Life (Cost: 10 points)\033[0m";
        gotoxy(55, 17); cout << "\033[1;32m2. Buy Speed Boost (Cost: 5 points)\033[0m";
        gotoxy(55, 19); cout << "\033[1;33m3. Buy Shield (Cost: 15 points)\033[0m";
        gotoxy(55, 21); cout << "\033[1;34m4. Back to Game\033[0m";
        gotoxy(55, 23); cout << "Select an option: ";

        char option;
        cin >> option;

        switch (option) {
            case '1':
                if (currentScore >= 10) {
                    lives++; 
                    currentScore -= 10;
                    gotoxy(55, 25); cout << "\033[1;32mExtra life purchased!\033[0m";
                } else {
                    gotoxy(55, 25); cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '2':
                if (currentScore >= 5) {
                    speed = max(speed - 5, 20); 
                    currentScore -= 5;
                    gotoxy(55, 25); cout << "\033[1;32mSpeed boost purchased!\033[0m";
                } else {
                    gotoxy(55, 25); cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '3':
                if (currentScore >= 15) {
                   
                    gotoxy(55, 25); cout << "\033[1;32mShield purchased! (Implement logic)\033[0m";
                    currentScore -= 15;
                } else {
                    gotoxy(55, 25); cout << "\033[1;31mNot enough points!\033[0m";
                }
                break;
            case '4':
                return; 
            default:
                gotoxy(55, 25); cout << "\033[1;31mInvalid option! Please try again.\033[0m";
                break;
        }
        getch(); 
    }
}

void play() {
    clearScreen();
    system("cls");
    init();
    currentScore = 0;
    lives = 3;
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
            moveDino(0,isDucking);  
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

        
        else if (ch == 'c' || ch == 'C') {  
            shopMenu();  
            clearScreen();  
            init();  
        }

        
        else if (ch == 27) {  
            break;
        }
    }
}



void instructions() {
    clearScreen();

    
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

    
     gotoxy(50, 15);
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
    clearScreen();

    gotoxy(50, 6); 
    cout << "Select your Dino: (\033[1;32m1\033[0m, \033[1;33m2\033[0m, or \033[1;34m3\033[0m)";

    gotoxy(50, 7); 
    cout << "\033[1;32m1.\033[0m Dino Type 1";

    gotoxy(50, 8); 
    cout << "\033[1;33m2.\033[0m Dino Type 2";

    gotoxy(50, 9); 
    cout << "\033[1;34m3.\033[0m Dino Type 3";

    gotoxy(50, 11); 
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
     loadHighScore();
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
     SetConsoleOutputCP(CP_UTF8);
    mainMenu();
    return 0;
}
