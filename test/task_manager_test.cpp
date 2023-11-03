#include "task-manager/task_manager.h"

#include "gtest/gtest.h"

TEST(AddTask, AddTask) {
  TaskManager taskManager;
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.toString(), "title, , date, Not Started,\n");
}
