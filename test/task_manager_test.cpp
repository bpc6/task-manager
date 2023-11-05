#include "task-manager/task_manager.h"

#include "gtest/gtest.h"

class TaskManagerFixture : public ::testing::Test {
 protected:
  TaskManager taskManager;
};

TEST_F(TaskManagerFixture, AddTaskSuccess) {
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.toString(), Task::header() + "title, date, Not Started, ,\n");
}

TEST_F(TaskManagerFixture, RemoveTaskSuccess) {
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.removeTask("title"), 0);
  EXPECT_EQ(taskManager.toString(), Task::header());
}

TEST_F(TaskManagerFixture, RemoveTaskFailure) {
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.removeTask("not title"), 1);
  EXPECT_EQ(taskManager.toString(), Task::header() + "title, date, Not Started, ,\n");
}

TEST_F(TaskManagerFixture, EditTitleSuccess) {
  taskManager.addTask(Task("title", "date"));
  taskManager.editTitle("title", "new title");

  EXPECT_EQ(taskManager.toString(), Task::header() + "new title, date, Not Started, ,\n");
}
