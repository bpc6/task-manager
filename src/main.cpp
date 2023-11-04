#include <iostream>

#include "task-manager/task_manager.h"

int main() {
  TaskManager taskManager;
  taskManager.addTask(Task("get groceries", "2023-10-31", "Done", ""));
  taskManager.addTask(Task("learn c++", "2024-01-01", "In Progress", "start small & build up!"));
  taskManager.toCsv("my_tasks.csv");
}
