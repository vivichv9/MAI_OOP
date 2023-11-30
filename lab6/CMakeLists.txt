cmake_minimum_required(VERSION 3.14)

project(lab6)

add_subdirectory(tests)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES FALSE ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Project lib
add_library(${PROJECT_NAME}_lib ${SOURCES})  

target_include_directories(${PROJECT_NAME}_lib PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_compile_options(${PROJECT_NAME}_lib PRIVATE "-g -Wall" "-Werror" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_lib PRIVATE "-fsanitize=undefined" "-fsanitize=address")

set_target_properties(${PROJECT_NAME}_lib PROPERTIES 
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)

# Executable
add_executable(${PROJECT_NAME}_exe ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)
target_compile_options(${PROJECT_NAME}_exe PRIVATE "-g -Wall" "-Werror" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_exe PRIVATE "-fsanitize=undefined" "-fsanitize=address")