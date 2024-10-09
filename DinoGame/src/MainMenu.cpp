#include <iostream>
#include <conio.h>  
#include <windows.h>

using namespace std;

void displayInstructions() {
    system("cls");
    cout << "Game Instructions";
    cout << "\n-----------------------------";
    cout << "\n1. Jump over obstacles to avoid collisions.";
    cout << "\n2. Use the 'Spacebar' to make your Dino jump.";
    cout << "\n3. Press 'P' to pause the game at any time.";
    cout << "\n4. Press 'Escape' to quit the game and return to the main menu.";
    cout << "\n\nGood luck, and have fun!";
    cout << "\n\nPress any key to return to the main menu.";
    getch();
}

int main() {
    setcursor(0, 0);

    do {
        system("cls");
        gotoxy(10, 5); cout << " -------------------------- ";
        gotoxy(10, 6); cout << " |        DINO RUN        | ";
        gotoxy(10, 7); cout << " -------------------------- ";
        gotoxy(10, 9); cout << "1. Play Dino Run Game";
        gotoxy(10, 10); cout << "2.View Instructions";
        gotoxy(10, 11); cout << "3.Exit Game";
        gotoxy(10, 13); cout << "Please Select an option: ";
        char userinput = getche();

        if (userinput == '1') play();
        else if (userinput == '2') instructions();
        else if (userinput == '3') exit(0);

    } while (1);

    return 0;
}
