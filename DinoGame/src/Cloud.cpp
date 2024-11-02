#include "Cloud.h"
#include <windows.h> 


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Cloud::draw() {
    gotoxy(5, 5); std::cout << "  _(  )_( )_  "; 
    gotoxy(5, 6); std::cout << " (_   _    _) "; 
    gotoxy(5, 7); std::cout << "   (_) (__)   "; 

    gotoxy(40, 5); std::cout << "  _(  )_( )_  "; 
    gotoxy(40, 6); std::cout << " (_   _    _) "; 
    gotoxy(40, 7); std::cout << "   (_) (__)   "; 

    gotoxy(75, 5); std::cout << "  _(  )_( )_  "; 
    gotoxy(75, 6); std::cout << " (_   _    _) "; 
    gotoxy(75, 7); std::cout << "   (_) (__)   "; 
}
