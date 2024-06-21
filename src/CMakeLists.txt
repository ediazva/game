include(FindRaylib)

include_directories(${PROJECT_SOURCE_DIR}/src)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(GAME_FLAGS -DGAME_DEBUG)
endif()

# ===============
# engine-lib
# ===============
add_library(engine-lib STATIC
  engine/engine.cc)
target_link_libraries(engine-lib raylib)
target_compile_definitions(engine-lib PUBLIC ${GAME_FLAGS})