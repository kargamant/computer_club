add_library(club Club.cpp ClubConfig.cpp)
target_link_libraries(club time)
target_include_directories(club PUBLIC .)