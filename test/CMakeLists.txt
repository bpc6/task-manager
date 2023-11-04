add_executable(task_test)
target_include_directories(task_test PRIVATE ../include)
target_sources(task_test PRIVATE
        main_test.cpp
        task_test.cpp
        ../src/task.cpp
        task_manager_test.cpp
        ../src/task_manager.cpp
)

target_link_libraries(task_test gtest_main)
add_test(NAME task_test COMMAND task_test)
