cmake_minimum_required (VERSION 3.10)

project(lab2)

add_compile_options(-Wall -g)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.hpp)

#
# library with common functions for tests and exe
#
add_library(${PROJECT_NAME}_lib
            ${SOURCES}
            ${INCLUDES})            

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

#
# project itself
#
add_executable(${PROJECT_NAME}_exe
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

add_dependencies(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)

#
# unit tests
#

# download googletest
configure_file(config/CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# add googletest to build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}_test_seven
               ${CMAKE_CURRENT_SOURCE_DIR}/test/test_seven.cpp)

set_target_properties(${PROJECT_NAME}_test_seven PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_seven PRIVATE
                           "${PROJECT_SOURCE_DIR}/src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_seven ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_seven ${PROJECT_NAME}_lib gtest_main)


add_executable(${PROJECT_NAME}_test_vector
               ${CMAKE_CURRENT_SOURCE_DIR}/test/test_vector.cpp)


set_target_properties(${PROJECT_NAME}_test_vector PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_vector PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_vector ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_vector ${PROJECT_NAME}_lib gtest_main)