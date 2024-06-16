//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_ORDER_H
#define FSOFT2024_1DC_3_ORDER_H

#include <list>
#include <iostream>
#include "Date.h"
#include "ProductList.h"

class Order{
protected:
    Date    date;
    float   value;
    ProductList products;
    void setValue(const float& pValue);

public:
    Order();
    float getValue();
    string getDate();

    void add(Product& product);
    void updateValueClient();
};

#endif //FSOFT2024_1DC_3_ORDER_H
