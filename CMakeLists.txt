message(STATUS "Building Connect4 Project")

cmake_minimum_required(VERSION 3.20)
project(Connect4)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)  # Includes the contents of the conanbuildinfo.cmake file.
conan_basic_setup()  # Prepares the CMakeList.txt for Conan.



enable_testing()
add_subdirectory(src)
add_subdirectory(test)