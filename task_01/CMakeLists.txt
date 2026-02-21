
set(SOURCES
        main.cpp
        src/utils.cpp)
add_executable(task_01 ${SOURCES})

target_include_directories(task_01 PRIVATE include)

target_link_libraries(task_01 PRIVATE benchmark::benchmark)