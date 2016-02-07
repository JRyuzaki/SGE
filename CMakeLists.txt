cmake_minimum_required(VERSION 3.4.3)

#Specify Project Name
project(SGE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Add Headers
include_directories(include)

#Collect all Source Files Recursive
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_library(sge STATIC ${SRC_FILES})
