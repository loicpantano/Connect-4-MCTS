cmake_minimum_required(VERSION 3.17)
project(connect4_mcts)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/include)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:sfml-system>
        $<TARGET_FILE:sfml-window>
        $<TARGET_FILE:sfml-graphics>
        $<TARGET_FILE:sfml-audio>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)