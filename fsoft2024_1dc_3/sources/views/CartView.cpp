//
// Created by nogue on 6/5/2024.
//

#include "../../headers/views/CartView.h"

using namespace std;


void CartView::printCartClient(list<Product> &products) {
    cout << "Products in cart" << endl;
    cout << "ProductID  ";
    cout << "Price  " ;
    cout << "Qty  ";
    cout << "Name";

    cout << endl;
    for (auto it=products.begin(); it != products.end(); ++it){
        cout <<it->getProductID()<<"  ";
        cout <<it->getSellingPrice()<<"€  ";
        cout <<it->getStock();
        cout << " " << it->getName() << endl;
    }
}

void CartView::empty() {
    cout << "Cart is empty. Back";
}

void CartView::printCartManager(list<Product> &products) {
    cout << "Products in cart" << endl;
    cout <<"ProductID";
    cout <<"Price" ;
    cout <<"Qty";
    cout << " Name";

    cout << endl;
    for (auto it=products.begin(); it != products.end(); ++it){
        cout << it->getProductID();
        cout << it->getStock();
        cout << " " << it->getName() << endl;
    }
}
