
project(00-Hello-World)


FILE(GLOB_RECURSE SOURCE_CPP_FILES "*.cpp") 
FILE(GLOB_RECURSE SOURCE_C_FILES "*.c") 
FILE(GLOB_RECURSE HEADER_FILES "*.h") 

add_executable(${PROJECT_NAME} ${SOURCE_CPP_FILES} ${SOURCE_C_FILES} ${HEADER_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Examples")
target_link_libraries(${PROJECT_NAME} Atlas-Framework)


