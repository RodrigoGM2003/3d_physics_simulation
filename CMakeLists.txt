cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER g++)

project(practicasIG LANGUAGES CXX)

# Project name
project(tfg)

# Set the C standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")

# Include directories
file(GLOB_RECURSE INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/src/*")

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/../freeglut.3.0.0.v140.1.0.2/sources/GL
)

# Source files
# file(GLOB SOURCES
#     "${CMAKE_SOURCE_DIR}/src/*.cpp"
# )
# Source files (recursively add all .cpp files within /src and its subdirectories)
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)


# Add executable
add_executable(main ${SOURCES})

# Link libraries
target_link_libraries(main
    ${CMAKE_SOURCE_DIR}/freeglut.3.0.0.v140.1.0.2/runtimes/win-x64/native/Release/freeglut.lib
    opengl32
)

# Set the output directory
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)