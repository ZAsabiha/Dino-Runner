#include <iostream>
#include <cstdlib>  
#include <windows.h>

using namespace std;

void instructions() {
    system("cls");
    cout << "Instructions";
    cout << "\n----------------";
    cout << "\n1. Avoid hurdles by jumping";
    cout << "\n2. Press 'Spacebar' to jump ";
    cout << "\n3. Press 'p' to pause game ";
    cout << "\n4. Press 'Escape' to exit from game";
    cout << "\n\nPress any key to go back to menu";
    getch();
}
int main() {
    int choice;

    displayMenu();
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Starting the game..." << endl;
            break;
        case 2:
            cout << "Restarting the game..." << endl;
            break;
        case 3:
            cout << "Opening settings..." << endl;
            break;
        case 4:
            cout << "Exiting the game..." << endl;
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }

    return 0;
}

