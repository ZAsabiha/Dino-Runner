#include "ScoreManager.h"
#include <fstream>

void writeTestResult(const std::string& testName, bool result) {
    std::ofstream resultFile("test_results.txt", std::ios_base::app); 
    if (resultFile.is_open()) {
        resultFile << testName << ": " << (result ? "PASS" : "FAIL") << "\n";
        resultFile.close();
    }
}


void resetTestFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << 0; 
        file.close();
    }
}

class TestScoreManager {
public:
    void runTests() {
        resetResultsFile();
        testInitialScores();
        testIncrementScore();
        testResetScore();
        testHighScore();
        testHighScorePersistence();
    }

private:
    void resetResultsFile() {
        std::ofstream resultFile("test_results.txt"); 
        if (resultFile.is_open()) {
            resultFile.close();
        }
    }

    void testInitialScores() {
        resetTestFile("test_highscore.txt");
        ScoreManager scoreManager("test_highscore.txt");

        bool result = (scoreManager.getCurrentScore() == 0) && (scoreManager.getHighScore() == 0);
        writeTestResult("testInitialScores", result);
    }

    void testIncrementScore() {
        resetTestFile("test_highscore.txt");
        ScoreManager scoreManager("test_highscore.txt");

        scoreManager.incrementScore();
        bool result = scoreManager.getCurrentScore() == 1;
        writeTestResult("testIncrementScore", result);
    }

    void testResetScore() {
        resetTestFile("test_highscore.txt");
        ScoreManager scoreManager("test_highscore.txt");

        scoreManager.incrementScore();
        scoreManager.resetScore();
        bool result = scoreManager.getCurrentScore() == 0;
        writeTestResult("testResetScore", result);
    }

    void testHighScore() {
        resetTestFile("test_highscore.txt");
        ScoreManager scoreManager("test_highscore.txt");

        scoreManager.incrementScore();
        scoreManager.checkAndSetHighScore();
        bool result = scoreManager.getHighScore() == 1;
        writeTestResult("testHighScore", result);
    }

    void testHighScorePersistence() {
        resetTestFile("test_highscore.txt");
        {
            ScoreManager scoreManager("test_highscore.txt");
            scoreManager.incrementScore();
            scoreManager.checkAndSetHighScore();
        }

        ScoreManager scoreManager("test_highscore.txt");
        bool result = scoreManager.getHighScore() == 1;
        writeTestResult("testHighScorePersistence", result);
    }
};

int main() {
    TestScoreManager test;
    test.runTests();
    return 0;
}
