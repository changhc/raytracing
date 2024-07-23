add_library(lib "")

target_sources(lib
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/vec3.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/vec3.h
	${CMAKE_CURRENT_LIST_DIR}/colour.h
  )

target_include_directories(lib
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
