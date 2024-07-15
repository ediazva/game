cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
if(MSVC)
  set(CXX_DEBUG_FLAGS "/Wall")
elseif(UNIX)
  set(CXX_DEBUG_FLAGS "-Wall")
endif()

message(STATUS "Compilando con flags: ${CXX_DEBUG_FLAGS}")

project(game)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(tests)
