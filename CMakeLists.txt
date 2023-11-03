cmake_minimum_required(VERSION 3.26)
project(task-manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source files
set(SOURCE_FILES
        src/main.cpp
        src/task.cpp
        src/task_manager.cpp
)

# Define header files
set(HEADER_FILES
        include/task.h
        include/task_manager.h
)

# Add the executable target & include directories
add_executable(task-manager ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(task-manager PRIVATE include)


# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(hello_test test/task_test.cpp src/task.cpp ${HEADER_FILES})
target_link_libraries(hello_test gtest_main)
add_test(NAME hello_test COMMAND hello_test)
