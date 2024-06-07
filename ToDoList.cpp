#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back({task, false});
        std::cout << "Added task: '" << task << "'\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int index) {
        if (index <= 0 || index > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }
        tasks[index - 1].completed = true;
        std::cout << "Marked task " << index << " as completed.\n";
    }

    void removeTask(int index) {
        if (index <= 0 || index > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Removed task " << index << ".\n";
    }
};

void printMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;
    std::string task;
    int taskNumber;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
}
