#include <iostream>
#include "MainMenu.h"

#include "Utility.h"

int main() {
    Utility::setcursor(0, 0);
    SetConsoleOutputCP(CP_UTF8);  
   
    
    MainMenu menu;
    menu.display();

   

    return 0;
}
