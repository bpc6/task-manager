#ifndef TASK_MANAGER_TASK_H
#define TASK_MANAGER_TASK_H

#include <string>

class Task {
private:
    std::string title;
    std::string description;
    std::string due;
    std::string status;

public:
    Task(std::string  title, std::string  dueDate);
    Task(std::string  title, std::string  dueDate, std::string  description);

    // Getters
    std::string getTitle() const;
    std::string getDescription() const;
    std::string getDue() const;
    std::string getStatus() const;

    // Setters
    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);
    void setDue(const std::string& newDue);
    void setStatus(const std::string& newStatus);

    std::string asRecord();
};

#endif //TASK_MANAGER_TASK_H