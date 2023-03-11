cmake_minimum_required(VERSION 3.0.0)
project(fence VERSION 0.1.0)

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.11.2
        )

FetchContent_MakeAvailable(json)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)