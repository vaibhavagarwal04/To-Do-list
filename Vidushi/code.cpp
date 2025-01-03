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

// Comparator for priority queue to sort by due date
struct CompareTasks {
    bool operator()(const Task& a, const Task& b) const {
        return a.dueDate > b.dueDate; // Min-heap based on dueDate
    }
};

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\nTo-Do List Application:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Delete Task\n";
        cout << "5. Sort Pending Tasks by Due Date\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear input buffer
                string desc, date, priority;
                cout << "Enter task description: ";
                getline(cin, desc);
                cout << "Enter due date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter priority (High/Medium/Low): ";
                cin >> priority;
                Task newTask(tasks.size() + 1, desc, date, priority);
                addTask(tasks, newTask);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int idComplete;
                cout << "Enter task ID to mark complete: ";
                cin >> idComplete;
                markComplete(tasks, idComplete);
                break;
            }
            case 4: {
                int idDelete;
                cout << "Enter task ID to delete: ";
                cin >> idDelete;
                deleteTask(tasks, idDelete);
                break;
            }
            case 5:
                sortPendingTasksByDate(tasks);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
