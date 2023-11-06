#ifndef TASK_MANAGER_TASK_MANAGER_H
#define TASK_MANAGER_TASK_MANAGER_H

#include <optional>
#include <vector>

#include "task-manager/task.h"

class TaskManager {
 private:
  std::vector<Task> tasks;
  std::optional<int> findTaskIndex(const std::string& title);

 public:
  void addTask(const Task& task);
  int removeTask(const std::string& title);
  int editTitle(const std::string& oldTitle, const std::string& newTitle);
  int editStatus(const std::string& oldTitle, const std::string& newStatus);

  std::string toString();
  void viewTasks();
  int toCsv(const std::string& csvPath);
  static TaskManager fromCsv(const std::string& csvPath);
};

#endif  // TASK_MANAGER_TASK_MANAGER_H
