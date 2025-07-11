#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to represent a task
struct Task {
    string description;
    bool done;
};

// Function to show all tasks
void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        cout << " [" << (tasks[i].done ? "Done" : "Not done") << "]\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n=== SIMPLE TO-DO LIST ===\n";
        cout << "1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        if (choice == 1) {
            string desc;
            cout << "Enter task: ";
            getline(cin, desc);
            tasks.push_back({desc, false});
            cout << "Task added.\n";

        } else if (choice == 2) {
            showTasks(tasks);

        } else if (choice == 3) {
            showTasks(tasks);
            if (!tasks.empty()) {
                int num;
                cout << "Enter task number to mark as done: ";
                cin >> num;
                if (num >= 1 && num <= tasks.size()) {
                    tasks[num - 1].done = true;
                    cout << "Task marked as done.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }

        } else if (choice == 4) {
            showTasks(tasks);
            if (!tasks.empty()) {
                int num;
                cout << "Enter task number to delete: ";
                cin >> num;
                if (num >= 1 && num <= tasks.size()) {
                    tasks.erase(tasks.begin() + num - 1);
                    cout << "Task deleted.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }

        } else if (choice == 5) {
            cout << "Exiting....\n";

        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

