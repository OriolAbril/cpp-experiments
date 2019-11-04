cmake_minimum_required(VERSION 3.10)

# set the project name
project("Integrate matrices and groups")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Compiler Options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /home/oriol/R/x86_64-pc-linux-gnu-library/3.6/RcppArmadillo/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /home/oriol/R/x86_64-pc-linux-gnu-library/3.6/Rcpp/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I /usr/share/R/include")

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

# add the mombf library
set(HEADER_MOMBF /home/oriol/Public/mombf/src/crossprodmat.h /home/oriol/Public/mombf/src/cstat.h)
add_library(mombf /home/oriol/Public/mombf/src/crossprodmat.cpp /home/oriol/Public/mombf/src/cstat.cpp ${HEADER_MOMBF} ${HEADER_RCPPARMA})
target_include_directories(mombf PRIVATE /home/oriol/Public/mombf/src)

# add the executable
add_executable(MatGroups matrices-groups.cpp ${HEADER_MOMBF})
target_include_directories(MatGroups PRIVATE /home/oriol/Public/mombf/src)

target_link_libraries(MatGroups ${ARMADILLO_LIBRARIES})
