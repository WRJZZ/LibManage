cmake_minimum_required(VERSION 3.28)
project(LibManage)

set(CMAKE_CXX_STANDARD 11)

add_executable(LibManage main.cpp
        Library.cpp
        Library.h
        Reader.cpp
        Reader.h
        Book.cpp
        Book.h
)
