cmake_minimum_required(VERSION 3.6)
project(BufferMgr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        headers/MyDB_BufferManager.h
        headers/MyDB_PageHandle.h
        source/MyDB_BufferManager.cc
        source/MyDB_PageHandle.cc)

add_executable(BufferMgr ${SOURCE_FILES})