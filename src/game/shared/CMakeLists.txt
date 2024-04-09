add_library(shared STATIC
    "${CMAKE_CURRENT_LIST_DIR}/globals.cc")
target_include_directories(shared PUBLIC "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(shared PUBLIC core entt)
