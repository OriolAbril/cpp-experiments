cmake_minimum_required(VERSION 3.10)

# set the project name
project("Integrate matrices and groups")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler Options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wpedantic -fstack-protector-strong")

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

# add crossprodmat.h
include_directories(include)

# add the executable
file(GLOB SOURCES "src/*.cpp")
add_executable(MatGroups ${SOURCES})

target_link_libraries(MatGroups ${ARMADILLO_LIBRARIES})
