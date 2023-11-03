# Add a test executable for your 'task_test'
add_executable(task_test)

# Include directories
target_include_directories(task_test PRIVATE ../include)

# Add your test source files
target_sources(task_test PRIVATE task_test.cpp ../src/task.cpp)

# Link with Google Test
target_link_libraries(task_test gtest_main)

# Register the 'task_test' with CTest
add_test(NAME task_test COMMAND task_test)
