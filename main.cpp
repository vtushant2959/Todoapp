#include <iostream>
#include <vector>
#include <string>

// Structure to represent a task
struct Task {
    std::string description;
    bool completed;
};

// Vector to store tasks
std::vector<Task> tasks;

// Function to add a new task
void addTask() {
    Task newTask;
    std::cout << "Enter new task: ";
    std::getline(std::cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added successfully.\n";
}

// Function to delete a task
void deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task deleted successfully.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

// Function to mark a task as completed
void completeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

// Function to list all tasks
void listTasks() {
    std::cout << "Your tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        std::cout << i << ". " << tasks[i].description << " - ";
        if (tasks[i].completed) {
            std::cout << "Completed\n";
        } else {
            std::cout << "Pending\n";
        }
    }
}

// Function to display help
void displayHelp() {
    std::cout << "Available commands:\n";
    std::cout << "1. add - Add a new task\n";
    std::cout << "2. delete <index> - Delete a task\n";
    std::cout << "3. done <index> - Mark a task as completed\n";
    std::cout << "4. list - List all tasks\n";
    std::cout << "5. help - Display this help message\n";
}

int main() {
    int choice;
    int taskIndex;

    while (true) {
        std::cout << "\nTodo App\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Delete Task\n";
        std::cout << "3. Mark Task as Done\n";
        std::cout << "4. List Tasks\n";
        std::cout << "5. Help\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in input buffer

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                std::cout << "Enter task index to delete: ";
                std::cin >> taskIndex;
                std::cin.ignore(); // Ignore newline left in input buffer
                deleteTask(taskIndex);
                break;
            case 3:
                std::cout << "Enter task index to mark as done: ";
                std::cin >> taskIndex;
                std::cin.ignore(); // Ignore newline left in input buffer
                completeTask(taskIndex);
                break;
            case 4:
                listTasks();
                break;
            case 5:
                displayHelp();
                break;
            case 6:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

