//
// Created by nogue on 6/5/2024.
//

#include "../../headers/model/Order.h"

Order::Order() {
    setValue(0);
}

float Order::getValue() {
    return this->value;
}

void Order::setValue(const float &pValue) {
    this->value = pValue;
}

void Order::add(Product &product) {
    this->products.add(product);
}

string Order::getDate() {
    return this->date.getDate();
}

void Order::updateValueClient() {
    float tempValue = 0;
    list<Product> tempProducts = this->products.getAll();
    auto it = tempProducts.begin();
    for (; it != tempProducts.end(); ++it){
        tempValue += (it->getSellingPrice() * it->getStock());
    }
    value = tempValue;
}