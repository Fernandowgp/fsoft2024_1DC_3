//
// Created by nogue on 6/5/2024.
//


#include <iostream>
#include "../../headers/model/ProductList.h"


list<Product>::iterator ProductList::search(const int &ProductID) {
    auto it = this->products.begin();
    for (; it != this->products.end(); ++it){
        if((it->getProductID()) == ProductID){
            return it;
        }
    }
    return it;
}

list<Product>::iterator ProductList::search(const Product &obj) {
    auto it = this->products.begin();
    for (; it != this->products.end(); ++it){
        if((it->getProductID()) == obj.getProductID()){
            return it;
        }
    }
    return it;}

list<Product> ProductList::getAll() {
    list<Product> newProductList (this->products);
    return newProductList;
}

Product* ProductList::get(const int &ProductID) {
    auto it = search(ProductID);
    if(it != this->products.end()){
        return &(*it);
    }
    return nullptr;
}

void ProductList::add(const Product obj) {
    auto it = search(obj);
    if(it == this->products.end()){
        this->products.push_back(obj);
    }else{
        string msg = "Product:" + to_string(obj.getProductID());
        //throw DuplicateEntryException(msg);
    }
}

void ProductList::edit(const string &name, const string &description, const string &category,
                       const string &brand, const int& ProductID, int stock, float sellingPrice,
                       bool isAvailable) {
    list<Product>::iterator it = search(ProductID);
    if(it != this->products.end()) {
        // Atualizar os atributos do produto com as novas edições
        it->setProductName(name);
        it->setDescription(description);
        it->setCategory(category);
        it->setBrand(brand);
        it->setStock(stock);
        it->setSellingPrice(sellingPrice);
        if(isAvailable){
            it->setAvailable();
        }else{
            it->setUnavailable();
        }
    }
}


ProductList ProductList::getAvailable() {
    ProductList returnProductList;
    auto it = this->products.begin();
    for (; it != this->products.end(); ++it){
        if(it->getIsAvailable() && it->getStock() > 0){
            Product tempProduct = it->get();
            returnProductList.add(tempProduct);
        }
    }
    return returnProductList;
}

void ProductList::remove(const Product &obj) {
    auto it = search(obj);
    if(it != this->products.end()){
        this->products.erase(it);
        return;
    }

    cout << "Product not found in list.\n";
}

void ProductList::reset() {
    this->products.clear();
}

list<Product>::iterator ProductList::searchByProductID(int &ProductID) {
    auto it = this->products.begin();
    for (; it != this->products.end(); ++it){
        if((*it) == ProductID){
            return it;
        }
    }
    return it;
}

void ProductList::changeAvailability(Product* product, ProductList* productsInCart) {
    bool isAvailable = product->getIsAvailable();
    Product* tempProduct = productsInCart->get(product->getProductID());

    if(!isAvailable) {
        product->setAvailable();
    }else if(tempProduct == nullptr){
        product->setUnavailable();
    }else{
        cout << "Product is in a cart. Aborting operation" << endl;
    }
}

