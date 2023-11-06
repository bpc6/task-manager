#include "task-manager/task.h"

#include <string>

#include "gtest/gtest.h"

// Test the constructors
TEST(TaskConstructorTest, ConstructorWithDescription) {
  Task task("Task Title", "2023-10-31", "Task Description");
  EXPECT_EQ(task.getTitle(), "Task Title");
  EXPECT_EQ(task.getDescription(), "Task Description");
  EXPECT_EQ(task.getDue(), "2023-10-31");
  EXPECT_EQ(task.getStatus(), "Not Started");
}

TEST(TaskConstructorTest, ConstructorWithoutDescription) {
  Task task("Task Title", "2023-10-31");
  EXPECT_EQ(task.getTitle(), "Task Title");
  EXPECT_EQ(task.getDescription(), "");  // Expect the default description
  EXPECT_EQ(task.getDue(), "2023-10-31");
  EXPECT_EQ(task.getStatus(), "Not Started");
}

TEST(TaskConstructorTest, ConstructorWithStatus) {
  Task task("Task Title", "2023-10-31", "In Progress", "Task Description");
  EXPECT_EQ(task.getTitle(), "Task Title");
  EXPECT_EQ(task.getDescription(), "Task Description");
  EXPECT_EQ(task.getDue(), "2023-10-31");
  EXPECT_EQ(task.getStatus(), "In Progress");
}

// Test the getters and setters
TEST(TaskGetterSetterTest, SettersAndGetters) {
  Task task("Task Title", "2023-10-31");

  task.setTitle("New Title");
  task.setDescription("New Description");
  task.setDue("2024-01-01");
  task.setStatus("In Progress");

  EXPECT_EQ(task.getTitle(), "New Title");
  EXPECT_EQ(task.getDescription(), "New Description");
  EXPECT_EQ(task.getDue(), "2024-01-01");
  EXPECT_EQ(task.getStatus(), "In Progress");
}

// Test the toString method
TEST(TaskToStringTest, TOSTRING) {
  Task task("Task Title", "2023-10-31", "Task Description");
  EXPECT_EQ(task.toString(), "Task Title, 2023-10-31, Not Started, Task Description,");
}

TEST(TaskFromString, Success) {
  std::string input = "Task Title, 2023-11-30, In Progress, Sample description,";

  Task task(input);

  EXPECT_EQ(task.getTitle(), "Task Title");
  EXPECT_EQ(task.getDue(), "2023-11-30");
  EXPECT_EQ(task.getDescription(), "Sample description");
  EXPECT_EQ(task.getStatus(), "In Progress");
}

TEST(TaskFromString, Failure) {
  std::string input = "Invalid Format";
  try {
    Task task(input);
    FAIL() << "Expected an exception, but no exception was thrown.";
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}
