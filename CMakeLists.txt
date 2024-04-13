cmake_minimum_required(VERSION 3.14)
project(QFORT LANGUAGES CXX VERSION 0.0.1)

set(BUILD_CLIENT ON CACHE BOOL "Build game client")
set(BUILD_SERVER ON CACHE BOOL "Build dedicated server")
set(DEFAULT_GAMEDIR "tfort" CACHE STRING "Content location")

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(PHYSFS_ARCHIVE_ZIP ON CACHE BOOL "" FORCE)

find_package(glfw3 QUIET)

if(NOT glfw3_FOUND)
    include(FetchContent)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(glfw3
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE)
    FetchContent_MakeAvailable(glfw3)
endif()

configure_file("${CMAKE_CURRENT_LIST_DIR}/config/cmake.hh.in" "${CMAKE_CURRENT_LIST_DIR}/config/cmake.hh")

add_subdirectory(deps/entt)
add_subdirectory(deps/glad)
add_subdirectory(deps/glm)
add_subdirectory(deps/physfs)
add_subdirectory(deps/spdlog)

add_subdirectory(core)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(shared)
add_subdirectory(main)
