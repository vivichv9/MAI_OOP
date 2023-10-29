cmake_minimum_required (VERSION 3.2)

add_library(${PROJECT_NAME}_vector 
                Vector.cpp
                Vector.hpp)

set_target_properties(${PROJECT_NAME}_vector PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED YES
                CXX_EXTENSIONS NO)

