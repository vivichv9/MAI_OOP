cmake_minimum_required (VERSION 3.10)

project(lab3)

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

# test Octagon target                 
add_executable(${PROJECT_NAME}_test_octagon
               ${CMAKE_CURRENT_SOURCE_DIR}/test/OctagonTest.cpp)

set_target_properties(${PROJECT_NAME}_test_octagon PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_octagon PRIVATE
                           "${PROJECT_SOURCE_DIR}/src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_octagon ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_octagon ${PROJECT_NAME}_lib gtest_main)

# test Vector target
add_executable(${PROJECT_NAME}_test_vector
               ${CMAKE_CURRENT_SOURCE_DIR}/test/VectorTest.cpp)


set_target_properties(${PROJECT_NAME}_test_vector PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_vector PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_vector ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_vector ${PROJECT_NAME}_lib gtest_main)

# test Square target
add_executable(${PROJECT_NAME}_test_square
               ${CMAKE_CURRENT_SOURCE_DIR}/test/SquareTest.cpp)


set_target_properties(${PROJECT_NAME}_test_square PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_square PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_square ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_square ${PROJECT_NAME}_lib gtest_main)

# test Triangle target
add_executable(${PROJECT_NAME}_test_triangle
               ${CMAKE_CURRENT_SOURCE_DIR}/test/TriangleTest.cpp)


set_target_properties(${PROJECT_NAME}_test_triangle PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_triangle PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_triangle ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_triangle ${PROJECT_NAME}_lib gtest_main)


# test Point target
add_executable(${PROJECT_NAME}_test_point
               ${CMAKE_CURRENT_SOURCE_DIR}/test/PointTest.cpp)


set_target_properties(${PROJECT_NAME}_test_point PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_point PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_point ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_point ${PROJECT_NAME}_lib gtest_main)
