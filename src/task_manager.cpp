#include "task-manager/task_manager.h"

#include <fstream>
#include <iostream>

void TaskManager::addTask(const Task& task) { tasks.push_back(task); }

int TaskManager::removeTask(const std::string& title) {
  int removeIdx = -1;
  for (int i = 0; i < tasks.size(); i++) {
    if (title == tasks[i].getTitle()) {
      removeIdx = i;
    }
  }
  if (removeIdx < 0) {
    std::cerr << "Task '" + title + "' was not found.";
    return EXIT_FAILURE;
  }
  tasks.erase(tasks.begin() + removeIdx);
  return EXIT_SUCCESS;
}

std::string TaskManager::toString() {
  std::string result = Task::header();
  for (Task task : tasks) {
    result += task.toString();
  }
  return result;
}

void TaskManager::viewTasks() { std::cout << toString(); }

int TaskManager::toCsv(const std::string& csvPath) {
  std::ofstream csv(csvPath, std::ios::out);
  if (!csv) {
    std::cerr << "Error opening the file." << std::endl;
    return EXIT_FAILURE;
  }
  csv << toString();
  csv.close();
  return EXIT_SUCCESS;
}
