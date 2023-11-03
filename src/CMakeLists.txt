# Define source files
set(SOURCE_FILES
        main.cpp
        task.cpp
        task_manager.cpp
)

# Define header files
set(HEADER_FILES
        ../include/task-manager/task.h
        ../include/task-manager/task_manager.h
)

# Add the source code to the main executable
target_sources(task-manager PRIVATE ${SOURCE_FILES} ${HEADER_FILES})
