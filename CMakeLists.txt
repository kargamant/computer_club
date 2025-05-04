cmake_minimum_required(VERSION 3.28)
SET(CMAKE_CXX_STANDARD 20)

file(COPY test_file.txt DESTINATION .)

if (UNIX)
    SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")
    add_compile_options(-g -O0)
endif (UNIX)

Project("COMPUTER_CLUB")

add_subdirectory(Outputter)
add_subdirectory(EventHandler)
add_subdirectory(Time)
add_subdirectory(Table)
add_subdirectory(Event)
add_subdirectory(Club)
add_subdirectory(Parser)

add_executable(main main.cpp)
target_include_directories(main PUBLIC .)
target_link_libraries(main parser club outputter)