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
        sources/model/Store.cpp
        headers/model/Login.h
        sources/model/Login.cpp
        headers/views/ClientView.h
        headers/views/ClientOrderView.h
        headers/views/ProductView.h
        headers/views/CartView.h
        sources/views/CartView.cpp
        sources/views/ClientOrderView.cpp
        sources/views/ClientView.cpp
        sources/views/ProductView.cpp
        headers/model/ClientOrder.h
        headers/model/Cart.h)
