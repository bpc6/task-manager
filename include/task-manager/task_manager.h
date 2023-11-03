#ifndef TASK_MANAGER_TASK_MANAGER_H
#define TASK_MANAGER_TASK_MANAGER_H

#include <vector>

#include "task-manager/task.h"

class TaskManager {
 private:
  std::vector<Task> tasks;

 public:
  void addTask(const Task& task);

  std::string toString();
};

#endif  // TASK_MANAGER_TASK_MANAGER_H
