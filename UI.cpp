// UI.cpp
#include "UI.h"
#include "Utility.h"

UI::UI() {

}





void UI::displayGameTitle() {

    Utility::gotoxy(55, 3);  std::cout << "\033[1;31m" << "  _____  _               _____             \n";
    Utility::gotoxy(55, 4);  std::cout << "\033[1;33m" << " |  __ \\(_)             |  __ \\            \n";
    Utility::gotoxy(55, 5);  std::cout << "\033[1;32m" << " | |  | |_ _ __   ___   | |__) |   _ _ __  \n";
    Utility::gotoxy(55, 6);  std::cout << "\033[1;34m" << " | |  | | | '_ \\ / _ \\  |  _  / | | | '_ \\ \n";
    Utility::gotoxy(55, 7);  std::cout << "\033[1;35m" << " | |__| | | | | | (_) | | | \\ \\ |_| | | | |\n";
    Utility::gotoxy(55, 8);  std::cout << "\033[1;36m" << " |_____/|_|_| |_|\\___/  |_|  \\_\\__,_|_| |_|\n";
    std::cout << "\033[0m"; 
}

void UI::instructions() {

    system("cls");

    // Display instructions with colored text
    Utility::gotoxy(50, 6);
    std::cout << "\033[36m ___           _                   _   _                 \033[0m";
    Utility::gotoxy(50, 7);
    std::cout << "\033[32m|_ _|_ __  ___| |_ _ __ _   _  ___| |_(_) ___  _ __  ___ \033[0m";
    Utility::gotoxy(50, 8);
    std::cout << "\033[33m | || '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __|\033[0m";
    Utility::gotoxy(50, 9);
    std::cout << "\033[35m | || | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\ \033[0m";
    Utility::gotoxy(50, 10);
    std::cout << "\033[31m|___|_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/\033[0m";
    Utility::gotoxy(50, 11);
    std::cout << "\033[34m---------------------------------------------------------\033[0m";

    Utility::gotoxy(50, 15);
    std::cout << "\033[31m1. Avoid hurdles by jumping\033[0m"; 
    Utility::gotoxy(50, 18);
    std::cout << "\033[32m2. Press 'Spacebar' to jump\033[0m"; 
    Utility::gotoxy(50, 21);
    std::cout << "\033[34m3. Press 'Esc' to exit\033[0m";      
    Utility::gotoxy(50, 24);
    std::cout << "\033[33m4. Collect coins for extra points\033[0m"; 

    Utility::gotoxy(90, 35);
    std::cout << "\033[36mPress any key to go back to the menu.\033[0m"; 
    getch();
}

void UI::drawClouds() {

    Utility::gotoxy(5, 5); std::cout << "\033[1;35m  _(  )_( )_  \033[0m"; 
    Utility::gotoxy(5, 6); std::cout << "\033[1;35m (_   _    _) \033[0m"; 
    Utility::gotoxy(5, 7); std::cout << "\033[1;35m   (_) (__)   \033[0m"; 

    Utility::gotoxy(50, 5); std::cout << "\033[1;35m  _(  )_( )_  \033[0m"; 
    Utility::gotoxy(50, 6); std::cout << "\033[1;35m (_   _    _) \033[0m"; 
    Utility::gotoxy(50, 7); std::cout << "\033[1;35m   (_) (__)   \033[0m"; 

    Utility::gotoxy(75, 5); std::cout << "\033[1;35m  _(  )_( )_  \033[0m"; 
    Utility::gotoxy(75, 6); std::cout << "\033[1;35m (_   _    _) \033[0m"; 
    Utility::gotoxy(75, 7); std::cout << "\033[1;35m   (_) (__)   \033[0m"; 
}

