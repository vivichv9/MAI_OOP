cmake_minimum_required(VERSION 3.2)

project(lab4)

add_subdirectory(containers)
add_subdirectory(test)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.hpp)


# Project itself
add_library(${PROJECT_NAME}_lib
              src/Point.cpp 
              src/Octagon.cpp 
              src/Square.cpp 
              src/Triangle.cpp)

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
              CXX_STANDARD 20
              CXX_STANDARD_REQUIRED YES
              CXX_EXTENSIONS NO)

target_include_directories(${PROJECT_NAME}_lib PRIVATE
              "${PROJECT_SOURCE_DIR}/src"
              "${PROJECT_SOURCE_DIR}/include")

target_compile_options(${PROJECT_NAME}_lib PUBLIC "-Wall")
add_dependencies(${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)
target_link_libraries(${PROJECT_NAME}_lib ${PROJECT_NAME}_vector)


# target Main executable
add_executable(${PROJECT_NAME}_exe main.cpp)

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
              CXX_STANDARD 20
              CXX_STANDARD_REQUIRED YES
              CXX_EXTENSIONS NO)

target_include_directories(${PROJECT_NAME}_exe PRIVATE
              "${PROJECT_SOURCE_DIR}/containers"
              "${PROJECT_SOURCE_DIR}/src"
              "${PROJECT_SOURCE_DIR}/include")

target_compile_options(${PROJECT_NAME}_exe PUBLIC "-Wall")
add_dependencies(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)         