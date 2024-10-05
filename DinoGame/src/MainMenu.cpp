#include <iostream>
#include <cstdlib>  

using namespace std;

void displayMenu() {
    system("cls");  

    cout << " ____ ___ _   _  ___    ____  _   _ _   _  " << endl;
    cout << "|  _ \\_ _| \\ | |/ _ \\  |  _ \\| | | | \\ | | " << endl;
    cout << "| | | | ||  \\| | | | | | |_) | | | |  \\| | " << endl;
    cout << "| |_| | || |\\  | |_| | |  _ <| |_| | |\\  | " << endl;
    cout << "|____/___|_| \\_|\\___/  |_| \\_\\\\___/|_| \\_| " << endl;

    cout << "\n1. Start Game" << endl;
    cout << "2. Restart Game" << endl;
    cout << "3. Settings" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
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

