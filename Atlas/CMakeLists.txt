cmake_minimum_required(VERSION 3.13.4)

project(AtlasFramework)

#Set the target directories
set(OUT_DIR "${CMAKE_BINARY_DIR}/bin/lib/")

#Add all source files to here, to be compiled.
set(SOURCE_FILES
    "src/main.cpp"
    "inc/atlas.h"
    )

include_directories(inc)


#Expose the library's public includes to other subprojects
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/inc
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)


#Set Library Dependencies

#Create the library itself

FILE(GLOB_RECURSE SOURCE_CPP_FILES "src/*.cpp") 
FILE(GLOB_RECURSE SOURCE_C_FILES "src/*.c") 
FILE(GLOB_RECURSE HEADER_FILES "inc/*.h") 

add_library(${LIB_NAME} SHARED ${SOURCE_CPP_FILES} ${SOURCE_C_FILES} ${HEADER_FILES})
#target_link_libraries(${LIB_NAME} ${LIB_DEPENDENCIES})

