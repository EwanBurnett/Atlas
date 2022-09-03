
cmake_minimum_required (VERSION 3.8)

project(Atlas)

set (CMAKE_CXX_STANDARD 20)

#Clone all git submodules into /External/

include_directories(Atlas/Framework/inc)
include_directories(Atlas/Interface/inc)

set(OUT_DIR "${CMAKE_BINARY_DIR}/bin/")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR}) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR}) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR}) 

add_subdirectory(Atlas/Framework/)
#add_subdirectory(Atlas/Interface/)
#add_subdirectory(Atlas/Editor/)
add_subdirectory(Examples//)




