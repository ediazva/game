set(RAYLIB_DIR "" CACHE PATH "Directorio de la librería Raylib")

if(NOT RAYLIB_DIR)
  message(FATAL_ERROR "Missing raylib dir")
endif()

if(UNIX)
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
else()
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
endif()
find_library(RAYLIB_LIBRARY raylib PATHS "${RAYLIB_DIR}/lib" REQUIRED)

message(STATUS "Raylib library: ${RAYLIB_LIBRARY}")

add_library(raylib INTERFACE)
target_include_directories(raylib INTERFACE "${RAYLIB_DIR}/include")
target_link_libraries(raylib INTERFACE "${RAYLIB_LIBRARY}")