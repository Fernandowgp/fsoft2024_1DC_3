cmake_minimum_required(VERSION 3.27)
project(fsoft2024_1dc_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(fsoft2024_1dc_3 main.cpp
        headers/views/View.h
        sources/views/View.cpp
        headers/views/Utils.h
        sources/views/Utils.cpp
        headers/controllers/Controller.h
        sources/controllers/Controller.cpp
        headers/model/Store.h
        sources/model/Store.cpp
        sources/model/Login.cpp
        headers/model/Manager.h
        sources/model/Manager.cpp
        headers/model/Client.h
        sources/model/Client.cpp
        exception/headers/InvalidDataException.h
        exception/sources/InvalidDataException.cpp
        headers/model/ClientList.h
        sources/model/ClientList.cpp
        mock/MockData.h
        mock/MockData.cpp
        sources/model/Date.cpp
        headers/model/Date.h
        headers/model/Product.h
        sources/model/Product.cpp
        headers/model/Cart.h
        headers/model/Order.h
        headers/model/ClientOrder.h
        headers/model/ProductList.h
        sources/model/Cart.cpp
        sources/model/ClientOrder.cpp
        sources/model/Order.cpp
        sources/model/ProductList.cpp
        headers/model/ClientOrderList.h
        headers/model/CompoStore.h
        sources/model/ClientOrderList.cpp
        sources/model/CompoStore.cpp
        headers/views/CartView.h
        headers/views/ProductView.h
        headers/views/ClientOrderView.h
        headers/views/ClientView.h
        sources/views/CartView.cpp
        sources/views/ClientOrderView.cpp
        sources/views/ClientView.cpp
        sources/views/ProductView.cpp
)
