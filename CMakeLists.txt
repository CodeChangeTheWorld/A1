cmake_minimum_required(VERSION 3.6)
project(A1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Main/BufferMgr/headers/MyDB_BufferManager.h
        Main/BufferMgr/headers/MyDB_PageHandle.h
        Main/BufferMgr/source/MyDB_BufferManager.cc
        Main/BufferMgr/source/MyDB_PageHandle.cc
        Main/BufferTest/source/BufferQUnit.cc
        Main/Catalog/headers/MyDB_Table.h
        Main/Catalog/source/MyDB_Table.cc
        Main/Qunit/headers/QUnit.h
        Main/BufferMgr/source/MyDB_Page.cc
        Main/BufferMgr/headers/MyDB_Page.h)
include_directories(
        Main/BufferMgr/headers
        Main/Catalog/headers
        Main/Qunit/headers
        )
add_executable(A1 ${SOURCE_FILES})