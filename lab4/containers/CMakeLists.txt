cmake_minimum_required (VERSION 3.22)

add_library(${PROJECT_NAME}_vector 
                src/Vector.cpp)

set_target_properties(${PROJECT_NAME}_vector PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED ON
                CXX_EXTENSIONS ON)

target_include_directories(${PROJECT_NAME}_vector PRIVATE
              "${PROJECT_SOURCE_DIR}/containers/include")

target_compile_options(${PROJECT_NAME}_vector PRIVATE "-Wall")
  
