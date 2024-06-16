//
// Created by nogue on 6/5/2024.
//

#include "../../headers/model/Cart.h"

Cart::Cart() {
    this->date = Date();
}

ClientOrder Cart::getClientOrder(Client* currentUser) {
    return {Date(), currentUser, value};
}


list<Product> Cart::getProducts() {
    return list<Product>(products.getAll());
}

void Cart::reset() {
    this->products.reset();
    updateValueClient();
}

void Cart::removeProduct(Product &obj) {
    int stockInCart = this->products.get(obj.getProductID())->getStock();
    if(stockInCart > 1){
        this->products.get(obj.getProductID())->setStock(stockInCart-1);
    }else{
        this->products.remove(obj);
    }
    if (this->getProducts().empty())
        setValue(0);
}

ProductList* Cart::getProductList() {
    return &this->products;
}

ProductList &Cart::getProductListRef() {
    return this->products;
}