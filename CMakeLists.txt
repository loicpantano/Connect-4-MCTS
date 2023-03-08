cmake_minimum_required(VERSION 3.17)
project(c4)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")
include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})


add_subdirectory(lib/SFML)
include_directories(lib/SFML/include)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
