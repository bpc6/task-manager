#ifndef TASK_MANAGER_TASK_H
#define TASK_MANAGER_TASK_H

#include <string>

class Task {
 private:
  std::string title;
  std::string due;
  std::string status;
  std::string description;

 public:
  Task(std::string title, std::string dueDate, std::string status, std::string description);
  Task(std::string title, std::string dueDate, std::string description);
  Task(std::string title, std::string dueDate);

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

  static std::string header();
  std::string toString();
};

#endif  // TASK_MANAGER_TASK_H
