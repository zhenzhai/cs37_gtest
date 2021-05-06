cmake_minimum_required(VERSION 3.12) # version can be different

project(gtest_minion) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

file(GLOB SOURCES "src/*.cpp") # compile all cpp files
add_executable(mytests ${SOURCES})

target_link_libraries(mytests PRIVATE gtest) # link google test to this executable
