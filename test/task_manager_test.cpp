#include "task-manager/task_manager.h"

#include "gtest/gtest.h"

class TaskManagerFixture : public ::testing::Test {
 protected:
  TaskManager taskManager;
};

TEST_F(TaskManagerFixture, AddTaskSuccess) {
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.toString(), Task::header() + "\ntitle, date, Not Started, ,\n");
}

TEST_F(TaskManagerFixture, RemoveTaskSuccess) {
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.removeTask("title"), 0);
  EXPECT_EQ(taskManager.toString(), Task::header() + "\n");
}

TEST_F(TaskManagerFixture, RemoveTaskFailure) {
  taskManager.addTask(Task("title", "date"));

  EXPECT_EQ(taskManager.removeTask("not title"), 1);
  EXPECT_EQ(taskManager.toString(), Task::header() + "\ntitle, date, Not Started, ,\n");
}

TEST_F(TaskManagerFixture, EditTitleSuccess) {
  taskManager.addTask(Task("title", "date"));
  taskManager.editTitle("title", "new title");

  EXPECT_EQ(taskManager.toString(), Task::header() + "\nnew title, date, Not Started, ,\n");
}

TEST_F(TaskManagerFixture, EditStatusSuccess) {
  taskManager.addTask(Task("title", "date"));
  taskManager.editStatus("title", "In Progress");

  EXPECT_EQ(taskManager.toString(), Task::header() + "\ntitle, date, In Progress, ,\n");
}

TEST_F(TaskManagerFixture, FromCsvSucces) {
  std::string csvName = "test_task_list.csv";

  taskManager.addTask(Task("get groceries", "2023-10-31", "Done", ""));
  taskManager.addTask(Task("learn c++", "2024-01-01", "In Progress", "start small & build up!"));
  taskManager.toCsv(csvName);

  TaskManager tm2 = TaskManager::fromCsv(csvName);
  EXPECT_EQ(taskManager.toString(), tm2.toString());

  // remove the artifact file
  std::remove(csvName.c_str());
}
