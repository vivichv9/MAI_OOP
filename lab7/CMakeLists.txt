cmake_minimum_required(VERSION 3.20)

project(lab7)

add_subdirectory(test)

add_library(${PROJECT_NAME}_lib
        src/npc.cpp
        src/squirrel.cpp
        src/werewolf.cpp
        src/druid.cpp)

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME}_lib PUBLIC "-Wall" "-Werror" "-g" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_lib PUBLIC "-fsanitize=undefined" "-fsanitize=address")
set_target_properties(${PROJECT_NAME}_lib PROPERTIES
        CXX_STANDART 20
        CXX_STANDART_REQUIRED ON)

add_executable(${PROJECT_NAME}_exe main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)