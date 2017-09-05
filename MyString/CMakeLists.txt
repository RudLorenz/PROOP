cmake_minimum_required(VERSION 3.8)
project(MyString)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp MyString.cpp MyString.h)
add_executable(MyString ${SOURCE_FILES})