#include <iostream>
#include <fstream>

using namespace std;

struct Task {
    char description[100];
    char status;

    Task() : status(' ') {
        description[0] = '\0';
    }

    Task(const char desc[], char stat = ' ') : status(stat) {
        int i = 0;
        while (desc[i] != '\0' && i < sizeof(description) - 1) {
            description[i] = desc[i];
            i++;
        }
        description[i] = '\0';
    }
};

void addTask(const char filename[], const char description[]) {
    ofstream ofs(filename, ios::app | ios::binary);
    if (!ofs.is_open()) {
        cout << "Error opening file to add task." << endl;
        return;
    }
    Task task(description);
    ofs.write(reinterpret_cast<const char*>(&task), sizeof(Task));
    cout << "Task added: " << description << endl;
    ofs.close();
}

void completeTask(const char filename[], int taskNumber) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file to complete task." << endl;
        return;
    }

    Task task;
    int index = 0;
    while (file.read(reinterpret_cast<char*>(&task), sizeof(Task))) {
        if (index == taskNumber - 1) {
            task.status = 'X';
            file.seekp(index * sizeof(Task), ios::beg);
            file.write(reinterpret_cast<const char*>(&task), sizeof(Task));
            cout << "Task " << taskNumber << " marked as complete." << endl;
            file.close();
            return;
        }
        index++;
    }
    cout << "Task number not found." << endl;
    file.close();
}

void displayTasks(const char filename[]) {
    ifstream ifs(filename, ios::binary);
    if (!ifs.is_open()) {
        cout << "Error opening file to display tasks." << endl;
        return;
    }

    Task task;
    int index = 1;
    cout << "\nTo-Do List:\n";
    while (ifs.read(reinterpret_cast<char*>(&task), sizeof(Task))) {
        cout << index << ". " << task.description
             << " [" << (task.status == 'X' ? "Complete" : "Incomplete") << "]\n";
        index++;
    }
    if (index == 1) {
        cout << "No tasks in the list." << endl;
    }
    ifs.close();
}

int main() {
    const char filename[] = "tasks.dat";
    int choice;
    char description[100];
    int taskNumber;

    do {
        cout << "\nTo-Do List Options:\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.getline(description, 100);
                addTask(filename, description);
                break;

            case 2:
                cout << "Enter task number to mark complete: ";
                cin >> taskNumber;
                completeTask(filename, taskNumber);
                break;

            case 3:
                displayTasks(filename);
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
