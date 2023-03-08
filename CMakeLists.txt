cmake_minimum_required(VERSION 3.17)
project(c4)

set(CMAKE_CXX_STANDARD 17)

# set the path to the directory where you extracted SFML
set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SFML/lib/cmake/SFML")

# find the SFML libraries
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)


file(GLOB_RECURSE SOURCES "src/*.cpp")
# Add the include directories
include_directories(include)

# Add the executable and link the SFML libraries
add_executable(${PROJECT_NAME} ${SOURCES})

# link the SFML libraries to your executable
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

