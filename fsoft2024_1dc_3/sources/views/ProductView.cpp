//
// Created by nogue on 6/5/2024.
//

#include "../../headers/views/ProductView.h"
#include "../../headers/views/Utils.h"
#include <iostream>


using namespace std;

Product ProductView::getProduct(const int &ProductID) {
    string name;
    string description;
    string category;
    string brand;
    int stock;
    float sellingPrice;
    bool isAvailable;

    name = Utils::getString("Name");
    description = Utils::getString("Description");
    category = Utils::getString("Category");
    brand = Utils::getString("Brand");
    stock = Utils::getNumber("Stock");
    sellingPrice = Utils::getFloat("SellingPrice");
    isAvailable = Utils::getBool("Product available? (1 - yes, 0 - no)? ");

    Product product(ProductID,name,description,category,brand,stock,sellingPrice,isAvailable);
    return product;
}


void ProductView::printProductListClient(list<Product>& products, const string& listTitle) {
    cout << listTitle << endl;
    cout <<"ProductID; ";
    cout <<"Name; ";
    cout <<"Price; " ;

    cout << endl;
    for (auto it=products.begin(); it != products.end(); ++it){
        cout << it->getProductID();
        cout << "; " << it->getName();
        cout << "; " << it->getSellingPrice() <<"€"<< endl;
    }
}

void ProductView::printProductClient(Product *product) {
    cout << "Name    : " << product->getName() << endl;
    cout << "Category: " <<  product->getCategory() << endl;
    cout << "Brand   : " <<  product->getBrand() << endl;
    cout << "ProductID     : " <<  product->getProductID() << endl;
    cout << "Stock   : " <<  product->getStock() << endl;
    cout << "Price   : " <<  product->getSellingPrice() << endl;
}


int ProductView::getProductID() {
    int ProductID;
    bool flag;
    do{
        ProductID = Utils::getUInt("Insert ProductID");
        flag = false;
        if(!ProductID){
            flag = true;
            invalidProductID();
        }
    }while(flag);
    return ProductID;
}

void ProductView::invalidProductID() {
    cout << "Invalid ProductID";
}

void ProductView::productUnavailable() {
    cout << "Product is not available. Aborting operation" << endl;
}
