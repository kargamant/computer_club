cmake_minimum_required(VERSION 4.0)
SET(CMAKE_CXX_STANDARD, 20)
Project("COMPUTER_CLUB")

add_subdirectory(Event)
add_subdirectory(Club)
add_subdirectory(Parser)

add_executable(main main.cpp)
target_include_directories(main PUBLIC .)
target_link_libraries(main parser club)