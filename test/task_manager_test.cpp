#include "task-manager/task_manager.h"

#include "gtest/gtest.h"

TEST(AddTask, AddTask) {
  TaskManager taskManager;
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.toString(), Task::header() + "title, date, Not Started, ,\n");
}

TEST(RemoveTask, Success) {
  TaskManager taskManager;
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.removeTask("title"), 0);
  EXPECT_EQ(taskManager.toString(), Task::header());
}

TEST(RemoveTask, Failure) {
  TaskManager taskManager;
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.removeTask("not title"), 1);
  EXPECT_EQ(taskManager.toString(), Task::header() + "title, date, Not Started, ,\n");
}
