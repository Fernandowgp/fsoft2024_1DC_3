//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_PRODUCTLIST_H
#define FSOFT2024_1DC_3_PRODUCTLIST_H

#include <list>
#include "Product.h"

class ProductList{
private:
    list<Product> products;
    list<Product>::iterator search(const int& ProductID);
    list<Product>::iterator search(const Product& obj);
    list<Product>::iterator searchByProductID(int& ProductID);
public:
    list<Product> getAll();
    ProductList getAvailable();
    Product* get(const int& ProductID);
    void add(Product obj);
    void changeAvailability(Product* product, ProductList* productsInCart);
    void edit(
            const string& name,
            const string& description,
            const string& category,
            const string& brand,
            const int& ProductID,
            int stock,
            float sellingPrice,
            bool isAvailable);
    void remove(const Product& obj); //Used only in Cart
    void reset();
};


#endif //FSOFT2024_1DC_3_PRODUCTLIST_H
