#include <iostream>
#include <fstream> // Include file stream library for file operations
#include <conio.h>
using namespace std;

class User {
protected:
    char name[50];
    char rollNo[15];
public:
    void getCredentials() {
        cout << "Enter your name: ";
        cin >> (name);
        cout << "Enter your roll number: ";
        cin >> (rollNo);
    }
    void displayCredentials() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

class Quiz : public User {
private:
    const char* questions[10];
    const char* options[10][4];
    int correctAnswers[10];
    int score;
public:
    Quiz() {
        score = 0;

        questions[0] = "Q1: What is 2 + 2?";
        questions[1] = "Q2: What is the capital of France?";
        questions[2] = "Q3: What is the square root of 16?";
        questions[3] = "Q4: What is 5 * 6?";
        questions[4] = "Q5: What is the largest planet in our solar system?";
        questions[5] = "Q6: What is the boiling point of water?";
        questions[6] = "Q7: Who wrote 'Hamlet'?";
        questions[7] = "Q8: What is the speed of light?";
        questions[8] = "Q9: What is the chemical symbol for gold?";
        questions[9] = "Q10: What is 9 + 10?";

        options[0][0] = "1. 3"; options[0][1] = "2. 4"; options[0][2] = "3. 5"; options[0][3] = "4. 6";
        options[1][0] = "1. Berlin"; options[1][1] = "2. Madrid"; options[1][2] = "3. Paris"; options[1][3] = "4. Rome";
        options[2][0] = "1. 3"; options[2][1] = "2. 4"; options[2][2] = "3. 5"; options[2][3] = "4. 6";
        options[3][0] = "1. 11"; options[3][1] = "2. 20"; options[3][2] = "3. 30"; options[3][3] = "4. 40";
        options[4][0] = "1. Earth"; options[4][1] = "2. Jupiter"; options[4][2] = "3. Mars"; options[4][3] = "4. Venus";
        options[5][0] = "1. 50 C"; options[5][1] = "2. 100 C"; options[5][2] = "3. 150 C"; options[5][3] = "4. 200 C";
        options[6][0] = "1. Charles Dickens"; options[6][1] = "2. William Shakespeare"; options[6][2] = "3. Jane Austen"; options[6][3] = "4. J.K. Rowling";
        options[7][0] = "1. 3.0 x 10^8 m/s"; options[7][1] = "2. 2.5 x 10^8 m/s"; options[7][2] = "3. 1.0 x 10^8 m/s"; options[7][3] = "4. 5.0 x 10^8 m/s";
        options[8][0] = "1. Au"; options[8][1] = "2. Ag"; options[8][2] = "3. Pb"; options[8][3] = "4. Hg";
        options[9][0] = "1. 18"; options[9][1] = "2. 19"; options[9][2] = "3. 20"; options[9][3] = "4. 21";

        correctAnswers[0] = 2;
        correctAnswers[1] = 3;
        correctAnswers[2] = 2;
        correctAnswers[3] = 3;
        correctAnswers[4] = 2;
        correctAnswers[5] = 2;
        correctAnswers[6] = 2;
        correctAnswers[7] = 1;
        correctAnswers[8] = 1;
        correctAnswers[9] = 2;
    }

    void startQuiz() {
        int answer;
        for (int i = 0; i < 10; ++i) {
            cout << questions[i] << endl;

            for (int j = 0; j < 4; ++j) {
                cout << options[i][j] << endl;
            }

            cout << "Enter your answer (1-4): ";
            answer = getch() - '0';

            if (answer == correctAnswers[i]) {
                score++;
            }
        }
    }

    void saveToFile() {
        ofstream outFile("quiz_result.txt");
        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "Roll Number: " << rollNo << endl;
            outFile << "Score: " << score << "/10" << endl;
            outFile.close();
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
    }

    void displayScore() {
        
        cout << "Your final score is: " << score << "/10" << endl;
        displayCredentials();

        // Save result to file
        saveToFile();

        // Display the saved content
        cout << "\nResults saved to file. Displaying saved data:\n";

        ifstream inFile("quiz_result.txt",ios::app);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Unable to open file for reading!" << endl;
        }
    }
};

int main() {
    Quiz q;

    q.getCredentials();
    q.startQuiz();
    q.displayScore();

    return 0;
}
