cmake_minimum_required(VERSION 3.22)

project(lab4)

add_subdirectory(containers)
# add_subdirectory(test)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES FALSE ${SOURCE_DIR}/*.cpp)

# Project itself
add_library(${PROJECT_NAME}_lib ${SOURCES})

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
              CXX_STANDARD 20
              CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME}_lib PUBLIC
              "${PROJECT_SOURCE_DIR}/containers/include"
              "${PROJECT_SOURCE_DIR}/include")

target_compile_options(${PROJECT_NAME}_lib PUBLIC "-Wall")
add_dependencies(${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)
target_link_libraries(${PROJECT_NAME}_lib PRIVATE ${PROJECT_NAME}_vector) 

# target Main executable
add_executable(${PROJECT_NAME}_exe main.cpp)

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
              CXX_STANDARD 20
              CXX_STANDARD_REQUIRED ON)

add_dependencies(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)         