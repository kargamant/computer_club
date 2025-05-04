add_library(event_handler EventHandler.cpp)
target_link_libraries(event_handler event club)
target_include_directories(event_handler PUBLIC .)