cmake_minimum_required( VERSION 3.12)

#project name and version
project(Hurricane VERSION 1.0)


#Let's make this library as dynamic one
file(GLOB  sourcefiles  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.*")
set(headers  "${CMAKE_CURRENT_SOURCE_DIR}/inc/")
add_library(hurricane SHARED ${sourcefiles})
target_include_directories(hurricane PUBLIC ${headers})