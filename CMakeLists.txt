cmake_minimum_required(VERSION 3.17)
project(ProductDatabase)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProductDatabase main.cpp sqlite3.c sqlite3.h sqlite3ext.h)