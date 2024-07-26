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
  engine/timer_manager.cc
  engine/debug.cc
  engine/level.cc
  engine/raylib.cc
  engine/mice_manager.cc
  engine/system_manager.cc
  engine/systems/draw.cc
  engine/systems/input.cc
  engine/systems/movement.cc
  engine/systems/hitbox.cc
  engine/systems/animation.cc
  engine/systems/shoot.cc
  engine/assets/texture_atlas.cc
)

set(ENGINE_LIBS raylib)
if(WIN32)
  list(APPEND ENGINE_LIBS Winmm.lib)
endif()

target_link_libraries(engine-lib mice-lib ${ENGINE_LIBS})
target_compile_definitions(engine-lib PUBLIC ${GAME_FLAGS})

add_executable(game
  game/main.cc
  game/app.cc
  game/level0.cc
  game/level1.cc)
target_link_libraries(game engine-lib)