add_library(server STATIC
    "${CMAKE_CURRENT_LIST_DIR}/main.cc")
target_include_directories(server PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(server PUBLIC core shared)
