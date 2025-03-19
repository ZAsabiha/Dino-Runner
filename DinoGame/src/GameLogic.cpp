#include "GameLogic.h"
#include "Utility.h"
#include <iostream> 
#include <conio.h>
#include <fstream> 
#include <windows.h>
#include<stdlib.h>
#include <time.h>
#include "GameOver.h"
#include "Global.h"


GameOver go;




void GameLogic::drawHurdle(int missileX, int missileY, bool &missileActive, bool isDucking) {
    static int plantX = 0;
    static int obstacleType = rand() % 3;
    static int score = 0;

    int dinoHeight = isDucking ? 2 : 4;
    int dinoHitboxY = isDucking ? 29 : 22;
    int hurdleX = hurdlePos - plantX;
    if (plantX > 0) {
        for (int i = 20; i <= 31; i++) {
            Utility::gotoxy(hurdlePos - plantX + 1, i);
            std::cout << "       ";  // Ensure full erasure
        }
    }
 
    if(!isDucking){
    if ( plantX == 56 && gameState.dinoY < dinoHeight) {
        gameState.lives--;
        Utility::gotoxy(40, 2);
        if (gameState.lives == 3) {
            std::cout << "\033[1;31mLIVES: \033[1;32m" << gameState.lives << "\033[0m";
        } else if (gameState.lives == 2) {
            std::cout << "\033[1;31mLIVES: \033[1;33m" << gameState.lives << "\033[0m";
        } else if (gameState.lives == 1) {
            std::cout << "\033[1;31mLIVES: \033[1;31m" << gameState.lives << "\033[0m";
        }

        if (gameState.lives == 0) {
            gameState.gameover = 1;
            go.displayGameOver();
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
                gameState.currentScore = score;

               
                for (int i = 26; i <= 31; i++) {
                    Utility::gotoxy(hurdleX, i);
                    std::cout << "      ";
                }

               
                Utility::gotoxy(11, 2);
                std::cout << "     ";
                Utility::gotoxy(11, 2);
                std::cout << score;

           
                if (gameState.speed > 30) {
                    gameState.speed--;
                }

            
                obstacleType = rand() % 3;
                return;
            }
        
    
            if (missileX >= hurdleX && missileX <= hurdleX + 15 && missileY >= 20 && missileY <= 23) {
                missileActive = false;
                plantX = 0; 
                score++;  
                gameState.currentScore = score;

              
                for (int i = 20; i <= 23; i++) {
                    Utility::gotoxy(hurdleX, i);
                    std::cout << "         ";
                }

             
                Utility::gotoxy(11, 2);
                std::cout << "     ";
                Utility::gotoxy(11, 2);
                std::cout << score;

             
                if (gameState.speed > 30) {
                    gameState.speed--;
                }

             
                obstacleType = rand() % 3;
                return;
            }
        }
    }

     switch (obstacleType) {
        case 0: 
        Utility::gotoxy(hurdleX+1, 26); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 27); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 28); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 29); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 30); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 31); std::cout << "      ";
            break;
        case 1: 
        Utility::gotoxy(hurdleX+1, 29); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 30); std::cout << "      ";
        Utility::gotoxy(hurdleX+1, 31); std::cout << "      ";
            break;
        case 2: 
        Utility::gotoxy(hurdleX+1, 20); std::cout << "         ";
        Utility::gotoxy(hurdleX+1, 21); std::cout << "         ";
        Utility::gotoxy(hurdleX+1, 22); std::cout << "         ";
        Utility::gotoxy(hurdleX+1, 23); std::cout << "         ";
            break;
    }

    
    switch (obstacleType) {
        case 0: 
        Utility::gotoxy(hurdleX, 26); std::cout << "\033[1;31m█  █  \033[0m";
        Utility::gotoxy(hurdleX, 27); std::cout << "\033[1;31m█  █  \033[0m";
        Utility::gotoxy(hurdleX, 28); std::cout << "\033[1;31m████  \033[0m";
        Utility::gotoxy(hurdleX, 29); std::cout << "\033[1;31m  █   \033[0m";
        Utility::gotoxy(hurdleX, 30); std::cout << "\033[1;31m  █   \033[0m";
        Utility::gotoxy(hurdleX, 31); std::cout << "\033[1;31m  █   \033[0m";
            break;
        case 1:
        Utility::gotoxy(hurdleX, 29); std::cout << "\033[1;34m███   \033[0m";
        Utility::gotoxy(hurdleX, 30); std::cout << "\033[1;34m████  \033[0m";
        Utility::gotoxy(hurdleX, 31); std::cout << "\033[1;34m ███  \033[0m";
            break;
        case 2: 
        Utility::gotoxy(hurdleX, 21); std::cout << "\033[1;33m █████   \033[0m";
        Utility::gotoxy(hurdleX, 22); std::cout << "\033[1;33m██    ██ \033[0m";
        Utility::gotoxy(hurdleX, 23); std::cout << "\033[1;33m  ████    \033[0m";
            break;
    }


    if (gameState.powerUpX == -1 && rand() % 50 == 0) {
        gameState.powerUpX = hurdlePos;
    
        int randomPowerUp = rand() % 3;
        if (randomPowerUp == 0) gameState.currentPowerUp = "❤️"; 
        else if (randomPowerUp == 1) gameState.currentPowerUp = "🟢"; 
        else gameState.currentPowerUp = "🔵"; 
    }
    
    if (gameState.powerUpX != -1) {
        int powerUpY = isDucking ? 27 : 24; // Correct Y-axis alignment
        Utility::gotoxy(gameState.powerUpX, powerUpY); 
        std::cout << " " << gameState.currentPowerUp << " ";
    
        Utility::gotoxy(gameState.powerUpX + 2, powerUpY); 
        std::cout << "   ";  
    
        gameState.powerUpX--;
    
        if (gameState.powerUpX == dinoPos && gameState.dinoY < dinoHeight) {
            if (gameState.currentPowerUp == "❤️" && gameState.lives < 3) {
                gameState.lives++;
                Utility::gotoxy(40, 2);
                std::cout << "\033[1;31mLIVES: ";
                if(gameState.lives == 3) {
                    std::cout << "\033[1;32m" << gameState.lives << "\033[0m";
                } else if(gameState.lives == 2) {
                    std::cout << "\033[1;33m" << gameState.lives << "\033[0m";
                } else if(gameState.lives == 1) {
                    std::cout << "\033[1;31m" << gameState.lives << "\033[0m";
                }
            } else if (gameState.currentPowerUp == "🟢") {
                gameState.currentScore += 10; 
                Utility::gotoxy(11, 2); 
                std::cout << gameState.currentScore;
            } else if (gameState.currentPowerUp == "🔵") {
                gameState.currentScore += 5; 
                Utility::gotoxy(11, 2); 
                std::cout << gameState.currentScore;
            }
    
            Utility::gotoxy(gameState.powerUpX, powerUpY);
            std::cout << "   ";
            gameState.powerUpX = -1;
    
            return;  // Important: Stop further execution immediately after collection
        }
    
        if (gameState.powerUpX < 0) {
            Utility::gotoxy(0, powerUpY);
            std::cout << "   ";  
            gameState.powerUpX = -1;
        }
    
    }
   
    plantX++;
    if (plantX >= hurdlePos - 6) {
        for (int x = 0; x < 6; x++) {
            for (int i = 20; i <= 31; i++) {
                if (obstacleType == 2 && (i < 21 || i > 23)) continue;
                Utility::gotoxy(hurdlePos - plantX + x, i);
                std::cout << "       ";
            }
            Sleep(5);
        }
    
        plantX = 0;
        score = gameState.currentScore;
        score++;
        gameState.currentScore = score;

        Utility::gotoxy(11, 2);
        std::cout << "     ";
        Utility::gotoxy(11, 2);
        std::cout << score;

        if (gameState.speed > 30) {
            gameState.speed--;
        }

        obstacleType = rand() % 3;
    }

}

void GameLogic::fireProjectile(int &missileX, int &missileY, bool &missileActive, bool isVertical) {
    if (!missileActive) {
        missileX = 15;
        missileY = (isVertical) ? 22 : 29;  
        missileActive = true;
    }

}

void GameLogic::moveProjectile(int &missileX, int &missileY, bool &missileActive, bool isVertical) {
    if (missileActive) {
        missileX++;  
        
       
        if (missileX > 80) missileActive = false;  

        
    }

}

void GameLogic::drawProjectile(int missileX, int missileY, bool missileActive, bool isVertical) {
    if (missileActive) {
        Utility::gotoxy(missileX, missileY);
        if (isVertical) {
            std::cout << "\033[1;32m 💣 \033[0m";  
        } else {
            std::cout << "\033[1;32m 🔨 \033[0m";  
        }
    }

}



