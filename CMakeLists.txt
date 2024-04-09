cmake_minimum_required(VERSION 3.14)
project(QFORT LANGUAGES CXX)
set(QFORT_SEMVER 0.0.1-alpha)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# UNDONE: check if this is enabled in launch
# and if it isn't, don't even bother trying to
# locate and mount compressed game content
set(PHYSFS_ARCHIVE_ZIP ON CACHE BOOL "" FORCE)

add_subdirectory(external/entt)
add_subdirectory(external/glm)
add_subdirectory(external/physfs)
add_subdirectory(external/spdlog)

add_subdirectory(src/core)
add_subdirectory(src/game/client)
add_subdirectory(src/game/launch)
add_subdirectory(src/game/server)
add_subdirectory(src/game/shared)
