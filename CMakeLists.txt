cmake_minimum_required(VERSION 3.10)

project(CalculatorProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Find GTest and GMock
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add source files
add_library(calculator_lib src/calculator.cpp inc/calculator.h)

# Add test executable
add_executable(calculator_tests unittest/calculator_test.cpp)

# Link libraries
target_link_libraries(calculator_tests calculator_lib ${GTEST_LIBRARIES} gmock gmock_main pthread)
