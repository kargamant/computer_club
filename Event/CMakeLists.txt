file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(event ${HEADERS} ${SOURCES})
target_link_libraries(event event_handler time)
target_include_directories(event PUBLIC .)
set_target_properties(event PROPERTIES LINKER_LANGUAGE CXX)