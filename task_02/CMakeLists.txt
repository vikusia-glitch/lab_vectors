
set(SOURCES
        main.cpp
        src/utils.cpp)
add_executable(task_02 ${SOURCES})

target_include_directories(task_02 PRIVATE include)

target_link_libraries(task_02 PRIVATE benchmark::benchmark)