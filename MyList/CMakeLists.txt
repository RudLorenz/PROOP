cmake_minimum_required(VERSION 3.8)
project(MyList)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp MyList.h)
add_executable(MyList ${SOURCE_FILES})