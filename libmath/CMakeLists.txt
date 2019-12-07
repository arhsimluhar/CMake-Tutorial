cmake_minimum_required( VERSION 3.12)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (pro_name "LibMath")
set (pro_version "1.0" )
project( ${pro_name} VERSION ${pro_version})
add_library(libmath  "${CMAKE_CURRENT_SOURCE_DIR}/src/swoosh.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/include/" )
target_include_directories(libmath PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


