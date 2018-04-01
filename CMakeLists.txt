cmake_minimum_required(VERSION 3.7)
project(CMSC28515HeatProject)

set(CMAKE_CXX_STANDARD 11)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)


set(SOURCE_FILES main.cpp)
add_executable(CMSC28515HeatProject ${SOURCE_FILES})
target_link_libraries (CMSC28515HeatProject Eigen3::Eigen)