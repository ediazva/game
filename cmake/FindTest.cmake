# Leer archivos del estilo:          test_<lib>*_<name>.cc
function(find_test_files)
  file(GLOB TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/test_*.cc")
  foreach(test_file ${TEST_FILES})
    get_filename_component(test_filename ${test_file} NAME_WE)
  
    string(REPLACE "_" ";" test_list "${test_filename}")
    list(POP_FRONT test_list test_list)

    if(NOT test_list)
      message(FATAL_ERROR "Error al leer ${test_filename}.cc")
    endif()
    
    add_executable(${test_filename} ${test_file})
    list(LENGTH test_list test_list_length)
    math(EXPR test_list_length "${test_list_length}-1")
    list(SUBLIST test_list 0 ${test_list_length} test_list)
    list(TRANSFORM test_list APPEND "-lib")
    target_link_libraries(${test_filename} ${test_list})
    target_include_directories(${test_filename} PUBLIC "${PROJECT_SOURCE_DIR}/src")

    message(STATUS "Añadiendo la prueba: ${test_filename} con las librerias ${test_list}")
  endforeach()
endfunction()