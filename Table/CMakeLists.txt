add_library(table Table.cpp)
target_link_libraries(table time)
target_include_directories(table PUBLIC .)