file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_library(event ${HEADERS})
target_include_directories(event INTERFACE .)
set_target_properties(event PROPERTIES LINKER_LANGUAGE CXX)