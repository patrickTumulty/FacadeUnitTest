cmake_minimum_required(VERSION 3.16.4)

project(FacadeUnitTest)

include(gtest.cmake)

find_package(Threads)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -pthread")

add_executable(facadeUT 
    src/main.cpp
    src/Facade.cpp
    )
add_executable(facadeUT-tests 
    test/test.cpp 
    src/Facade.cpp)

target_link_libraries(facadeUT-tests ${CMAKE_THREADS_LIBS_INIT} gtest)