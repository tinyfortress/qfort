add_library(client STATIC
    "${CMAKE_CURRENT_LIST_DIR}/main.cc")
target_include_directories(client PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(client PUBLIC core shared)
