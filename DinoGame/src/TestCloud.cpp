#include "Cloud.h"
#include <windows.h>
#include <iostream>

class CloudTest : public Cloud {
public:
    int coordinates[9][2];  
    int index = 0;         

   
    void gotoxy(int x, int y) override {
        if (index < 9) {
            coordinates[index][0] = x;
            coordinates[index][1] = y;
            index++;
        }
    }

    
    bool verifyCoordinates() {
       
        int expected[9][2] = {
            {5, 5}, {5, 6}, {5, 7},
            {40, 5}, {40, 6}, {40, 7},
            {75, 5}, {75, 6}, {75, 7}
        };

        for (int i = 0; i < 9; ++i) {
            if (coordinates[i][0] != expected[i][0] || coordinates[i][1] != expected[i][1]) {
                return false;  
            }
        }
        return true;
    }
};

class TestCloud {
public:
    void runTests() {
        if (testDraw()) {
           
            outputResult("testDraw: PASS\n");
        } else {
           
            outputResult("testDraw: FAIL\n");
        }
    }

private:
    bool testDraw() {
        CloudTest cloudTest;
        cloudTest.draw();  

        return cloudTest.verifyCoordinates();  
    }

    void outputResult(const char* result) {
       
        for (const char* c = result; *c != '\0'; ++c) {
            putchar(*c);  
        }
    }
};

int main() {
    TestCloud test;
    test.runTests();
    return 0;
}
