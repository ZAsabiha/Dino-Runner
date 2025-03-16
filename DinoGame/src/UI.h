// UI.h
#ifndef UI_H
#define UI_H

#include <iostream>
#include <conio.h>  // For getch(), gotoxy()
#include <windows.h> 
#include "Utility.h" // For gotoxy()

class UI {
public:
    // Constructor and destructor
    UI();
    

    // Function to display the game title
    void displayGameTitle();

    // Function to show the instructions
    void instructions();

    // Function to draw clouds
    void drawClouds();



};

#endif // UI_H
