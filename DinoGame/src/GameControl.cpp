
#include "GameControl.h"

#include "Global.h"
#include "Utility.h"
#include <iostream>

void GameControl::init() {
    system("cls");
    gameState.gameover = 0;
    Utility::gotoxy(40, 2); 
    std::cout << "\033[1;31mLIVES: \033[1;32m" << gameState.lives << "\033[0m";
    gameState.score.loadHighScore();
}

void GameControl::play() {
    Utility::clearScreen();
    system("cls");
    init();
    gameState.currentScore = 0;
    gameState.lives = 3;
    char ch;
    int jumpHeight;
    int missileX = 15, missileY = -1;  
    bool missileActive = false;        
    bool isVertical = false;          
    bool isDucking = false; 
    bool isBigJump = false;           

    while (true) {
        while (!kbhit()) {
            if (gameState.gameover == 1) return;

            gameState.score.scoring();
            gameState.dino.moveDino(0, isDucking);  // Call moveDino from Dino class
            gameState.gl.drawHurdle(missileX, missileY, missileActive, isDucking);  
            gameState.ui.drawClouds();

            if (missileActive) {
                gameState.gl.moveProjectile(missileX, missileY, missileActive, isVertical); 
                gameState.gl.drawProjectile(missileX, missileY, missileActive, isVertical);
            }

            Sleep(100);
        }

        ch = getch();
        
        if (ch == 's' || ch == 'S' && !isDucking) {  
            jumpHeight = 0;
            if (isBigJump) {  
                while (jumpHeight < 12) {  
                    gameState.dino.moveDino(1, isDucking);  // Call moveDino from Dino class
                    gameState.gl.drawHurdle(missileX, missileY, missileActive, isDucking);
                    jumpHeight++;
                }
                isBigJump = false;  
            } else {
                while (jumpHeight < 12) {
                    gameState.dino.moveDino(1, isDucking);  // Call moveDino from Dino class
                    gameState.gl.drawHurdle(missileX, missileY, missileActive, isDucking);
                    jumpHeight++;
                }
            }
            while (jumpHeight > 0) {
                gameState.dino.moveDino(2, isDucking);  // Call moveDino from Dino class
                gameState.gl.drawHurdle(missileX, missileY, missileActive, isDucking);
                jumpHeight--;
            }
        } 

        else if ((ch == 'f' || ch == 'F') && gameState.horizontalWeaponActive) {  
            if (!missileActive && gameState.horizontalMissileCount > 0) {
                isVertical = false;
                missileY = 29;
                gameState.gl.fireProjectile(missileX, missileY, missileActive, isVertical);  
                gameState.horizontalMissileCount--; 
                if (gameState.horizontalMissileCount == 0) gameState.horizontalWeaponActive = false;  
            }
        }

        else if ((ch == 'v' || ch == 'V') && gameState.verticalWeaponActive) {  
            if (!missileActive && gameState.verticalMissileCount > 0) {
                isVertical = true;
                missileY = 21;
                gameState.gl.fireProjectile(missileX, missileY, missileActive, isVertical);  
                gameState.verticalMissileCount--;  
                if (gameState.verticalMissileCount == 0) gameState.verticalWeaponActive = false;  
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
            gameState.shop.shopMenu();  
            Utility::clearScreen();
            init();
        }

 
        else if (ch == 27) {
            break;
        }
    }
}
