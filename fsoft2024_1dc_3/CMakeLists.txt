cmake_minimum_required(VERSION 3.27)
project(fsoft2024_1dc_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(fsoft2024_1dc_3 main.cpp
        headers/views/View.h
        sources/views/View.cpp
        headers/views/Utils.h
        sources/views/Utils.cpp
        headers/model/Cliente.h
        sources/model/Cliente.cpp
        headers/controllers/Controller.h
        sources/controllers/Controller.cpp
        headers/model/Store.h
        sources/model/Store.cpp)
