//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_CARTVIEW_H
#define FSOFT2024_1DC_3_CARTVIEW_H

#include "../model/Cart.h"
#include "ProductView.h"

class CartView{
public:
    void printCartClient(list<Product>& products);
    void printCartManager(list<Product>& products);
    void empty();

};

#endif //FSOFT2024_1DC_3_CARTVIEW_H
