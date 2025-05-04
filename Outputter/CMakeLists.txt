add_library(outputter Outputter.cpp)
target_link_libraries(outputter event club)
target_include_directories(outputter PUBLIC .)