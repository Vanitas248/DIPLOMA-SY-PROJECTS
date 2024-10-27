#include <iostream>
#include <fstream>

using namespace std;

class User {
protected:
    char name[50];
    char rollNo[15];

public:
    void getCredentials() {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your roll number: ";
        cin >> rollNo;
    }

    void displayCredentials() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }

    void saveToFile(ofstream& file, int score) {
        file << "Name: " << name << endl;
        file << "Roll Number: " << rollNo << endl;
        file << "Final Score: " << score << "/10" << endl;
        file << "------------------------" << endl;
    }
};

class Quiz : public User {
private:
    const char* questions[10] = {
        "Q1: What is 2 + 2?",
        "Q2: What is the capital of France?",
        // ... other questions
    };

    const char* options[10][4] = {
        {"1. 3", "2. 4", "3. 5", "4. 6"},
        // ... other options
    };

    int correctAnswers[10];
    int score;

public:
    Quiz() {
        score = 0;
        correctAnswers[0] = 2;
        correctAnswers[1] = 3;
        // ... other correct answers
    }

    void startQuiz() {
        int answer;
        for (int i = 0; i < 10; ++i) {
            cout << questions[i] << endl;
            for (int j = 0; j < 4; ++j) {
                cout << options[i][j] << endl;
            }

            cout << "Enter your answer (1-4): ";
            cin >> answer;

            if (answer == correctAnswers[i]) {
                score++;
            }
        }
    }

    void displayScore() {
        cout << "Your final score is: " << score << "/10" << endl;
        displayCredentials();
    }

    void saveScoreToFile() {
        ofstream file("result.txt", ios::app);  // Open file in append mode

        if (!file) {
            cout << "Error: Could not open file!" << endl;
        } else {
            saveToFile(file, score);
            file.close();
            cout << "Results saved to result.txt" << endl;
        }
    }
};

int main() {
    Quiz q;

    q.getCredentials();
    q.startQuiz();
    q.displayScore();
    q.saveScoreToFile();

    return 0;   
}
