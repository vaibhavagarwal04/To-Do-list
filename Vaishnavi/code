#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class Task {
    public:
    int id;
    string description;
    string dueDate; // Stored in format "YYYY-MM-DD"
    string priority;
    bool isComplete;
    
    Task(int id, const string& description, const string& dueDate, const string& priority)
    : id(id), description(description), dueDate(dueDate), priority(priority), isComplete(false) {}
    
    // Check if a task is overdue
    bool isOverdue() const {
        time_t now = time(0);
        tm currentDate = *localtime(&now);
        char buffer[11];
        strftime(buffer, 11, "%Y-%m-%d", &currentDate);
        string currentDateStr(buffer);
        return !isComplete && dueDate < currentDateStr;
    }
};

// Add a new task to the list
void addTask(vector<Task>& tasks, const Task& newTask) {
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// View all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (const auto& task : tasks) {
        string status = task.isComplete ? "Complete" : "Incomplete";
        string overdue = task.isOverdue() ? " (Overdue!)" : "";
        cout << task.id << " | " << task.description << " | " << task.priority << " | Due: " << task.dueDate << " | Status: " << status << overdue << "\n";
    }
}
