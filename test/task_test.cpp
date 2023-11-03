#include <string>
#include "task-manager/task.h"
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
    EXPECT_EQ(task.getDescription(), ""); // Expect the default description
    EXPECT_EQ(task.getDue(), "2023-10-31");
    EXPECT_EQ(task.getStatus(), "Not Started");
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

// Test the asRecord method
TEST(TaskAsRecordTest, AsRecord) {
    Task task("Task Title", "2023-10-31", "Task Description");
    EXPECT_EQ(task.asRecord(), "Task Title, Task Description, 2023-10-31, Not Started");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
