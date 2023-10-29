cmake_minimum_required (VERSION 3.2)

# download googletest
configure_file(../config/CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
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


# Test Octagon Tatget
add_executable(${PROJECT_NAME}_test_octagon OctagonTest.cpp)

set_target_properties(${PROJECT_NAME}_test_octagon PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED YES
                CXX_EXTENSIONS NO)

target_include_directories(${PROJECT_NAME}_test_octagon PRIVATE
                "${PROJECT_SOURCE_DIR}/containers"
                "${PROJECT_SOURCE_DIR}/src"
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_octagon ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_octagon ${PROJECT_NAME}_lib gtest_main)

# Test Point target
add_executable(${PROJECT_NAME}_test_point PointTest.cpp)

set_target_properties(${PROJECT_NAME}_test_point PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED YES
                CXX_EXTENSIONS NO)

target_include_directories(${PROJECT_NAME}_test_point PRIVATE
                "${PROJECT_SOURCE_DIR}/containers"
                "${PROJECT_SOURCE_DIR}/src"
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_point ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_point ${PROJECT_NAME}_lib gtest_main)


# Test Triangle target
add_executable(${PROJECT_NAME}_test_triangle TriangleTest.cpp)

set_target_properties(${PROJECT_NAME}_test_triangle PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED YES
                CXX_EXTENSIONS NO)

target_include_directories(${PROJECT_NAME}_test_triangle PRIVATE
                "${PROJECT_SOURCE_DIR}/containers"
                "${PROJECT_SOURCE_DIR}/src"
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_triangle ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_triangle ${PROJECT_NAME}_lib gtest_main)


# Tets Square target
add_executable(${PROJECT_NAME}_test_square SquareTest.cpp)

set_target_properties(${PROJECT_NAME}_test_square PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED YES
                CXX_EXTENSIONS NO)

target_include_directories(${PROJECT_NAME}_test_square PRIVATE
                "${PROJECT_SOURCE_DIR}/containers"
                "${PROJECT_SOURCE_DIR}/src"
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")                

add_dependencies(${PROJECT_NAME}_test_square ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_square ${PROJECT_NAME}_lib gtest_main)
