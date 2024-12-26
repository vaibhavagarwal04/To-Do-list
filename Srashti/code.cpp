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

// Sort pending tasks by due date
void sortPendingTasksByDate(const vector<Task>& tasks) {
    priority_queue<Task, vector<Task>, CompareTasks> queue;
    for (const auto& task : tasks) {
        if (!task.isComplete) {
            queue.push(task);
        }
    }

    if (queue.empty()) {
        cout << "No pending tasks.\n";
        return;
    }

    cout << "Pending Tasks Sorted by Due Date:\n";
    while (!queue.empty()) {
        const Task& task = queue.top();
        string overdue = task.isOverdue() ? " (Overdue!)" : "";
        cout << task.id << " | " << task.description << " | Due: " << task.dueDate << overdue << "\n";
        queue.pop();
    }
}
