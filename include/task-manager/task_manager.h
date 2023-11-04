#ifndef TASK_MANAGER_TASK_MANAGER_H
#define TASK_MANAGER_TASK_MANAGER_H

#include <vector>

#include "task-manager/task.h"

class TaskManager {
 private:
  std::vector<Task> tasks;

 public:
  void addTask(const Task& task);
  int removeTask(const std::string& title);

  std::string toString();
  void viewTasks();
  int toCsv(const std::string& csvPath);
};

#endif  // TASK_MANAGER_TASK_MANAGER_H
