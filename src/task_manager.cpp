#include "task-manager/task_manager.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::optional<int> TaskManager::findTaskIndex(const std::string& title) {
  int taskIdx = -1;
  for (int i = 0; i < tasks.size(); i++) {
    if (title == tasks[i].getTitle()) {
      taskIdx = i;
    }
  }
  if (taskIdx < 0) {
    std::cerr << "Task '" + title + "' was not found.";
    return std::nullopt;
  }
  return taskIdx;
}

void TaskManager::addTask(const Task& task) { tasks.push_back(task); }

int TaskManager::removeTask(const std::string& title) {
  std::optional<int> removeIdx = findTaskIndex(title);
  if (!removeIdx.has_value()) {
    return EXIT_FAILURE;
  }
  tasks.erase(tasks.begin() + removeIdx.value());
  return EXIT_SUCCESS;
}

int TaskManager::editTitle(const std::string& oldTitle, const std::string& newTitle) {
  std::optional<int> editIdx = findTaskIndex(oldTitle);
  if (!editIdx.has_value()) {
    return EXIT_FAILURE;
  }
  tasks[editIdx.value()].setTitle(newTitle);
  return EXIT_SUCCESS;
}

int TaskManager::editStatus(const std::string& oldTitle, const std::string& newStatus) {
  std::optional<int> editIdx = findTaskIndex(oldTitle);
  if (!editIdx.has_value()) {
    return EXIT_FAILURE;
  }
  tasks[editIdx.value()].setStatus(newStatus);
  return EXIT_SUCCESS;
}

std::string TaskManager::toString() {
  std::string result = Task::header() + "\n";
  for (Task task : tasks) {
    result += task.toString() + "\n";
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

TaskManager TaskManager::fromCsv(const std::string& csvPath) {
  TaskManager taskManager;
  std::ifstream file(csvPath);
  if (file.is_open()) {
    std::string line;
    std::getline(file, line);
    if (line != Task::header()) {
      throw std::invalid_argument("Invalid TaskManager CSV format");
    }
    while (std::getline(file, line)) {
      taskManager.addTask(Task::fromString(line));
    }
    file.close();
  }
}
