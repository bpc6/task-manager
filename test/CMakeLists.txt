add_executable(main_test)
target_include_directories(main_test PRIVATE ../include)
target_sources(main_test PRIVATE
        main_test.cpp
        task_test.cpp
        ../src/task.cpp
        task_manager_test.cpp
        ../src/task_manager.cpp
)

target_link_libraries(main_test gtest_main)
add_test(NAME main_test COMMAND main_test)
