#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const  string& task) {
        tasks.push_back({task, false});
         cout << "Added task: '" << task << "'\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
             cout << "No tasks in the list.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
             cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int index) {
        if (index <= 0 || index > tasks.size()) {
             cout << "Invalid task number.\n";
            return;
        }
        tasks[index - 1].completed = true;
         cout << "Marked task " << index << " as completed.\n";
    }

    void removeTask(int index) {
        if (index <= 0 || index > tasks.size()) {
             cout << "Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
         cout << "Removed task " << index << ".\n";
    }
};

void printMenu() {
     cout << "\nTo-Do List Manager\n";
     cout << "1. Add Task\n";
     cout << "2. View Tasks\n";
     cout << "3. Mark Task as Completed\n";
     cout << "4. Remove Task\n";
     cout << "5. Exit\n";
     cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;
     string task;
    int taskNumber;

    while (true) {
        printMenu();
         cin >> choice;

        switch (choice) {
            case 1:
                 cout << "Enter task description: ";
                 cin.ignore();
                 getline( cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                 cout << "Enter task number to mark as completed: ";
                 cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                 cout << "Enter task number to remove: ";
                 cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                 cout << "Exiting...\n";
                return 0;
            default:
                 cout << "Invalid option. Please try again.\n";
        }
    }
}
