include(FindRaylib)
include(CopyResources)

include_directories(${PROJECT_SOURCE_DIR}/src)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(GAME_FLAGS -DGAME_DEBUG)
endif()

# ===============
# engine-lib
# ===============
add_library(engine-lib STATIC
  engine/engine.cc
  engine/raylib.cc
  engine/debug.cc
  componentes/genericos.h
  engine/assets/texture_atlas.cc
)
target_link_libraries(engine-lib raylib)
target_compile_definitions(engine-lib PUBLIC ${GAME_FLAGS})
