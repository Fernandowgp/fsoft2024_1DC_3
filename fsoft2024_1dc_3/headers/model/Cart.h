//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_CART_H
#define FSOFT2024_1DC_3_CART_H

#include "Order.h"
#include "ClientOrder.h"
#include "../views/Utils.h"

class ClientOrder;
class Client;

class Cart: public Order{
public:
    Cart();
    void reset();
    void removeProduct(Product& obj);
    list<Product> getProducts();
    ProductList* getProductList();
    ProductList& getProductListRef();
    ClientOrder getClientOrder(Client* currentUser);
};


#endif //FSOFT2024_1DC_3_CART_H
