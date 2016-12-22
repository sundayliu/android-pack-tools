cmake_minimum_required(VERSION 2.8)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(FIXELF C CXX)

set(FIXELF_SOURCES 
    fixelf.cpp
    )

set(CMAKE_MODULE_PATH ${MERGEELF_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
#set(CMAKE_EXE_LINKER_FLAGS "-static")
#add_subdirectory(src bin)

add_executable(fixelf ${FIXELF_SOURCES})