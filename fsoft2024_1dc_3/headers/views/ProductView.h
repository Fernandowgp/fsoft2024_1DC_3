//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_PRODUCTVIEW_H
#define FSOFT2024_1DC_3_PRODUCTVIEW_H

#include <list>
#include "../model/Product.h"
#include "View.h"

class ProductView {
public:
    Product getProduct(const int& ProductID);
    void printProductClient(Product* product);
    void printProductListClient(list<Product>& products, const string& listTitle);
    int getProductID();
    void invalidProductID();
    void productUnavailable();

};


#endif //FSOFT2024_1DC_3_PRODUCTVIEW_H
