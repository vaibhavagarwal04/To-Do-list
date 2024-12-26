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
// Mark a task as complete
void markComplete(vector<Task>& tasks, int taskId) {
    for (auto& task : tasks) {
        if (task.id == taskId) {
            task.isComplete = true;
            cout << "Task marked as complete!\n";
            return;
        }
    }
    cout << "Task ID not found!\n";
}
//Remove a task
void deleteTask(vector<Task>& tasks, int taskId) {
    auto it = remove_if(tasks.begin(), tasks.end(),
                        [taskId](const Task& task) { return task.id == taskId; });
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Task ID not found!\n";
    }
}
