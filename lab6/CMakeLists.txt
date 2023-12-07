cmake_minimum_required(VERSION 3.14)

project(lab6)

add_subdirectory(tests)

# Project lib
add_library(${PROJECT_NAME}_lib
            src/field/square.cpp
            src/game_manager/game_manager.cpp
            src/npc/druid.cpp
            src/npc/npc.cpp
            src/npc/squirrel.cpp
            src/npc/werewolf.cpp
            src/observer/interface/IObserver.h
            src/observer/interface/IObservable.h
        src/logs/Log.h
            src/logs/file_logger.h
            src/logs/file_logger.cpp
            src/logs/console_logger.h
            src/logs/console_logger.cpp
            src/factory/NPCFactory.cpp
            src/factory/NPCFactory.h
            src/visitor/visitor.cpp
            src/visitor/visitor.h
        src/logs/Log.cpp
)

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_compile_options(${PROJECT_NAME}_lib PUBLIC "-g" "-Wall" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_lib PUBLIC "-fsanitize=undefined" "-fsanitize=address")

set_target_properties(${PROJECT_NAME}_lib PROPERTIES 
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED ON
                      CXX_EXTENSIONS OFF)

# Executable
add_executable(${PROJECT_NAME}_exe ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)
