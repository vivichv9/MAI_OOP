cmake_minimum_required(VERSION 3.2)

project(lab4)

add_subdirectory(containers)
add_subdirectory(test)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.hpp)

add_library(${PROJECT_NAME}_lib 
              ${SOURCES}
              ${INCLUDES})

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
              CXX_STANDARD 20
              CXX_STANDARD_REQUIRED YES
              CXX_EXTENSIONS NO)

add_dependencies(${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)
target_link_libraries(${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)

add_executable(${PROJECT_NAME}_exe main.cpp)

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
              CXX_STANDARD 20
              CXX_STANDARD_REQUIRED YES
              CXX_EXTENSIONS NO)

add_dependencies(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)         