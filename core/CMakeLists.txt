add_library(core STATIC
    "${CMAKE_CURRENT_LIST_DIR}/cmdline.cc"
    "${CMAKE_CURRENT_LIST_DIR}/crc64.cc"
    "${CMAKE_CURRENT_LIST_DIR}/epoch.cc"
    "${CMAKE_CURRENT_LIST_DIR}/strtools.cc"
    "${CMAKE_CURRENT_LIST_DIR}/vfstools.cc")
target_include_directories(core PUBLIC "${CMAKE_SOURCE_DIR}")
target_link_libraries(core PUBLIC entt glm physfs spdlog)

if(WIN32)
    # Microsoft-vendored C++ libraries for Windows seem to generally
    # mald over people using quote-unquote unsafe functions from libc
    target_compile_definitions(core PUBLIC _CRT_SECURE_NO_WARNINGS)
endif()

if(MSVC)
    target_compile_options(core PUBLIC /wd4244)
    target_compile_options(core PUBLIC /wd4267)
endif()
