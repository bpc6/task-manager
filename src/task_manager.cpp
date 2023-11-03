#include "task-manager/task_manager.h"

void TaskManager::addTask(const Task& task) { tasks.push_back(task); }

std::string TaskManager::toString() {
  std::string result;
  for (Task task : tasks) {
    result += task.toString();
  }
  return result;
}
