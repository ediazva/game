include(FindLibSFML)

add_library(engine-lib
  engine/engine.cc)
target_include_directories(engine-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(engine-lib sfml-system)