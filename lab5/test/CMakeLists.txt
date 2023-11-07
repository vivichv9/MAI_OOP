cmake_minimum_required(VERSION 3.22)

# download googletest
configure_file(${PROJECT_SOURCE_DIR}/cmake/CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
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


# Test List Target
add_executable(${PROJECT_NAME}_test_list test_list.cpp)

set_target_properties(${PROJECT_NAME}_test_list PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME}_test_list PRIVATE
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_list ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_list ${PROJECT_NAME}_lib gtest_main)

# Test Allocator Target
add_executable(${PROJECT_NAME}_test_allocator test_allocator.cpp)

set_target_properties(${PROJECT_NAME}_test_allocator PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME}_test_allocator PRIVATE
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_allocator ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_allocator ${PROJECT_NAME}_lib gtest_main)