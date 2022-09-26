cmake_minimum_required (VERSION 3.21)


# Configure
project(Atlas)

set(CMAKE_CXX_STANDARD 17) #Target C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)    #Enable IDE Folders
option(ATLAS_BUILD_TESTS "Builds the GTest Test Project" ON)
option(ATLAS_BUILD_DOCS "Builds HTML/PDF Documentation using Doxygen" ON)
option(ATLAS_BUILD_EXAMPLES "Builds Example Projects" ON)

set(OUT_DIR "${PROJECT_SOURCE_DIR}/bin/") #Output to [ROOT]/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUT_DIR}/") #Output Project Files to [ROOT]/bin/
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUT_DIR}/lib/") #Output Static Library to [ROOT]/bin/lib/
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUT_DIR}/shared/") #Output Dynamic Library to [ROOT]/bin/shared/


# Validate Git Submodules
find_package(Git REQUIRED)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULES "Validate Submodules at Build" ON)
    if(GIT_SUBMODULES)
        message(STATUS "Validating Submodules")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}.\nPlease checkout instead.")
        endif()
    endif()
endif()

# GLFW
IF(NOT EXISTS "${PROJECT_SOURCE_DIR}/External/GLFW/README.md")
    message(FATAL_ERROR "Submodule GLFW was not found!\nGit Submodule Validation failed. Please try again.")
endif()

# ASSIMP
IF(NOT EXISTS "${PROJECT_SOURCE_DIR}/External/ASSIMP/Readme.md")
    message(FATAL_ERROR "Submodule ASSIMP was not found!\nGit Submodule Validation failed. Please try again.")
endif()

# TinyXML2
IF(NOT EXISTS "${PROJECT_SOURCE_DIR}/External/TinyXML2/readme.md")
    message(FATAL_ERROR "Submodule TinyXML2 was not found!\nGit Submodule Validation failed. Please try again.")
endif()

# OpenAL Soft
IF(NOT EXISTS "${PROJECT_SOURCE_DIR}/External/OpenAL-Soft/README.md")
    message(FATAL_ERROR "Submodule OpenAL Soft was not found!\nGit Submodule Validation failed. Please try again.")
endif()

# LUA
IF(NOT EXISTS "${PROJECT_SOURCE_DIR}/External/LUA/README.md")
    message(FATAL_ERROR "Submodule Lua was not found!\nGit Submodule Validation failed. Please try again.")
endif()

# GoogleTest
IF(ATLAS_BUILD_TESTS AND NOT EXISTS "${PROJECT_SOURCE_DIR}/External/GoogleTest/README.md")
    message(FATAL_ERROR "Submodule Google Test was not found!\nGit Submodule Validation Failed. Please try again.\nOptionally, try building with ATLAS_BUILD_TESTS set to OFF.")
endif()

# Doxygen [Optional] Build Docs
IF(ATLAS_BUILD_DOCS)
    message(STATUS "Generating Documentation with Doxygen")
    find_package(Doxygen QUIET)
    if(NOT DOXYGEN_FOUND) 
        if(NOT EXISTS "${PROJECT_SOURCE_DIR}/External/Doxygen/Readme.md")
            message(FATAL_ERROR "Submodule Doxygen was not found!")
        endif()

        message(WARNING "Doxygen Installation Not Found\nAttempting to build Doxygen manually...")

        execute_process(COMMAND "mkdir build && cd build && ${CMAKE_COMMAND} .."
                WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/External/Doxygen/"
                RESULT_VARIABLE DOXYGEN_BUILD_RESULT)
            
        if(NOT DOXYGEN_BUILD_RESULT EQUAL "0")
            message(FATAL_ERROR "Doxygen Build Failed. Please attempt to install Doxygen Manually.")
        endif()

        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/External/Doxygen/Bin/Doxygen.exe")
            set(DOXYGEN_EXECUTABLE "${CMAKE_CURRENT_SOURCE_DIR}/External/Doxygen/Bin/Doxygen.exe")
        else()
            message(FATAL_ERROR "Please Build Doxygen from source.")
        endif()

    endif()

    execute_process(COMMAND ${DOXYGEN_EXECUTABLE} "DOXYFILE"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Docs/"
    RESULT_VARIABLE DOXYGEN_GEN_RESULT)

    if(NOT DOXYGEN_GEN_RESULT EQUAL "0")
        
    endif()
endif()


include_directories(Atlas/Framework/inc) #Add Include Directories for the Framework and Interface libraries
include_directories(Atlas/Interface/inc)

if(ATLAS_BUILD_EXAMPLES)
    message(STATUS "Generating Example Projects")
    add_subdirectory(Examples/)
endif()

if(ATLAS_BUILD_TESTS)
    message(STATUS "Generating Test Project")
    add_subdirectory(Tests/)
endif()

# Find required packages
find_package(OpenGL REQUIRED)

# Build Atlas Framework Static Library
add_subdirectory(External/assimp EXCLUDE_FROM_ALL)
add_subdirectory(External/glfw EXCLUDE_FROM_ALL)
add_subdirectory(External/openal-soft EXCLUDE_FROM_ALL)
add_subdirectory(External/tinyxml2 EXCLUDE_FROM_ALL)

FILE(GLOB_RECURSE FRAMEWORK_CPP_FILES "Atlas/Framework/src/*.cpp")
FILE(GLOB_RECURSE FRAMEWORK_C_FILES "Atlas/Framework/src/*.c")
FILE(GLOB_RECURSE FRAMEWORK_H_FILES "Atlas/Framework/inc/*.h")

add_library(Atlas-Framework STATIC ${FRAMEWORK_CPP_FILES} ${FRAMEWORK_C_FILES} ${FRAMEWORK_H_FILES})
target_include_directories(Atlas-Framework 
    PUBLIC "Atlas/Framework/inc/"
    PUBLIC ${GLFW_INCLUDE_DIRS}
    PUBLIC ${ASSIMP_INCLUDE_DIRS}
    PUBLIC ${OPENAL_INCLUDE_DIRS}
    PUBLIC "External/TinyXML2/"
    PUBLIC "External/Lua/"
)

target_link_libraries(Atlas-Framework ${OPENGL_LIBRARIES} glfw tinyxml2 OpenAL assimp ${LUA_LIBRARIES})

# Build Atlas Interface Shared Library
FILE(GLOB_RECURSE INTERFACE_CPP_FILES "Atlas/Interface/src/*.cpp")
FILE(GLOB_RECURSE INTERFACE_C_FILES "Atlas/Interface/src/*.c")
FILE(GLOB_RECURSE INTERFACE_H_FILES "Atlas/Interface/inc/*.h")

add_library(Atlas-Interface SHARED ${INTERFACE_CPP_FILES} ${INTERFACE_C_FILES} ${INTERFACE_H_FILES})

target_link_libraries(Atlas-Interface Atlas-Framework)


# Build Atlas Tests Test Project

# Validate NUGet Packages

# Clone the Editor Project 
INCLUDE_EXTERNAL_MSPROJECT(Atlas-Editor "${PROJECT_SOURCE_DIR}/Atlas/Editor/Atlas-Editor.csproj")














