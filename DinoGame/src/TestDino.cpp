#include "Dino.h"
#include <cassert>
#include <iostream>

class TestDino {
public:
    void testMove() {
        Dino dino;

       
        try {
            dino.move(0); 
            dino.move(2);  
            dino.move(1);  
            std::cout << "testMove passed.\n";
        } catch (...) {
            assert(false && "testMove failed: move function threw an error with valid inputs.");
        }
    }

    void testSetCursor() {
        Dino dino;

      
        try {
            dino.setCursor(false, 0);  
            dino.setCursor(true, 20); 
            std::cout << "testSetCursor passed.\n";
        } catch (...) {
            assert(false && "testSetCursor failed: setCursor function threw an error with valid inputs.");
        }
    }

    void testGotoxy() {
        Dino dino;

       
        try {
            dino.gotoxy(10, 5); 
            std::cout << "testGotoxy passed.\n";
        } catch (...) {
            assert(false && "testGotoxy failed: gotoxy function threw an error.");
        }
    }

    void runTests() {
        testMove();
        testSetCursor();
        testGotoxy();

        std::cout << "All tests in TestDino passed.\n";
    }
};

int main() {
    TestDino tester;
    tester.runTests();
    return 0;
}
