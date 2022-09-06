cmake_minimum_required (VERSION 3.21.3)

project(Atlas)

set (CMAKE_CXX_STANDARD 20)

#Clone all git submodules into /External/

INCLUDE_EXTERNAL_MSPROJECT(Atlas-Editor "${PROJECT_SOURCE_DIR}/Atlas/Editor/Atlas-Editor.csproj")

include_directories(Atlas/Framework/inc)
include_directories(Atlas/Interface/inc)

set(OUT_DIR "${CMAKE_BINARY_DIR}/bin/")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUT_DIR}/lib/") 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUT_DIR}/shared/") 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUT_DIR}/") 

add_subdirectory(Atlas/)
add_subdirectory(Examples/)




