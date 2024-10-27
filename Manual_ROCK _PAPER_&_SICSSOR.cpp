#include <iostream>

using namespace std;

void display_choice(int choice) {
    switch (choice) {
        case 1:
            cout << "Rock";
            break;
        case 2:
            cout << "Paper";
            break;
        case 3:
            cout << "Scissors";
            break;
    }
}

int get_computer_choice(int seed) {
    return (seed % 3) + 1;
}

int main() {
    int user_choice, computer_choice;
    static int seed = 0;

    cout << "Welcome to Rock-Paper-Scissors Game!\n";
    cout << "Choose your option:\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter your choice (1-3): ";
    cin >> user_choice;

    if (user_choice < 1 || user_choice > 3) {
        cout << "Invalid choice! Please select a number between 1 and 3." << endl;
        return 0;
    }

    computer_choice = get_computer_choice(seed++);
    
    cout << "\nYou chose: ";
    display_choice(user_choice);
    cout << "\nComputer chose: ";
    display_choice(computer_choice);
    cout << "\n";

    if (user_choice == computer_choice) {
        cout << "It's a tie!";
    } else if ((user_choice == 1 && computer_choice == 3) ||
               (user_choice == 2 && computer_choice == 1) ||
               (user_choice == 3 && computer_choice == 2)) {
        cout << "You win!";
    } else {
        cout << "Computer wins!";
    }

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}
