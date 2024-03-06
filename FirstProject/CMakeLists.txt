cmake_minimum_required(VERSION 3.27)
project(FirstProject)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/headers)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/sources)
include_directories(${PROJECT_HEADERS_DIR})
include_directories(${PROJECT_SOURCES_DIR})
set(SOURCE_FILES
        main.cpp
        ${PROJECT_HEADERS_DIR}/factorial.h
        ${PROJECT_SOURCES_DIR}/factorial.cpp
        headers/pl2.h
        sources/pl2.cpp
        headers/pl3.h
        sources/pl3.cpp
)
add_executable(FirstProject ${SOURCE_FILES})
