cmake_minimum_required(VERSION 3.9)
project(DPlusPlus)

find_package(cpprestsdk REQUIRED)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

file(GLOB SOURCE_FILES Src/*.cpp)

add_library(DPlusPlus ${SOURCE_FILES})
target_include_directories(DPlusPlus PUBLIC vendor)
target_include_directories(DPlusPlus PUBLIC Include)

target_link_libraries(DPlusPlus PRIVATE cpprestsdk::cpprest)

