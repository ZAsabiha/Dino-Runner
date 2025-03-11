#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>

class Utility {
public:
    static void gotoxy(int x, int y);
    static void setcursor(bool visible, DWORD size);
    static void clearScreen();
};

#endif
