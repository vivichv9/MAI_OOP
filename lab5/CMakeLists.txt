cmake_minimum_required(VERSION 3.10)

project(lab5)

add_subdirectory(test)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

# Project main lib
add_library(${PROJECT_NAME}_lib ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME}_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_compile_options(${PROJECT_NAME}_lib PUBLIC "-Wall" "-Werror" "-g" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_lib PUBLIC "-fsanitize=undefined" "-fsanitize=address")

# main executable target
add_executable(${PROJECT_NAME}_exe ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)