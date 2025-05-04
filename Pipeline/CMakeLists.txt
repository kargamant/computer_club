add_library(pipeline Pipeline.cpp)
target_link_libraries(pipeline club event_handler outputter parser)
target_include_directories(pipeline PUBLIC .)