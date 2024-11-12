#include <iostream>
#include <conio.h>

using namespace std;

class Missile {
private:
    int x, y;
    bool active;
    int rangeCounter;
    const int maxRange = 30;

public:
    Missile() : x(0), y(0), active(false), rangeCounter(0) {}

    void fire(int startX, int startY) {
        if (!active) {
            x = startX;
            y = startY;
            active = true;
            rangeCounter = 0;
        }
    }

    void move() {
        if (active) {
            x++;
            rangeCounter++;
            if (x >= 75 || rangeCounter > maxRange) {
                deactivate();
            }
        }
    }

    void draw() const {
        if (active) {
            gotoxy(x, y);
            cout << "\033[1;32m █ \033[0m";
        } else {
            clear();
        }
    }

    void deactivate() {
        active = false;
        clear();
    }

    void clear() const {
        gotoxy(x, y);
        cout << " ";
    }

    bool isActive() const {
        return active;
    }
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
