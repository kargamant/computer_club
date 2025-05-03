add_library(parser Parser.cpp)
target_link_libraries(parser club event)
target_include_directories(parser PUBLIC .)