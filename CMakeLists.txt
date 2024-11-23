cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CXX_DEBUG_FLAGS "-Wall")

project(game)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(tests)

# file(COPY data DESTINATION ${CMAKE_BINARY_DIR}/src)
# file(COPY data DESTINATION ${CMAKE_BINARY_DIR}/tests)