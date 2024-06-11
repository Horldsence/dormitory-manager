cmake_minimum_required (VERSION 3.10)

project (dormitory-manager)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Inc")
aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/Src" SRC_DIR)

add_executable(dormitory-manager ${SRC_DIR})