//
// Created by Luís on 26/05/2024.
//

#ifndef FSOFT2024_1DC_3_CONTROLLER_H
#define FSOFT2024_1DC_3_CONTROLLER_H

#include "../views/View.h"
#include "../model/Store.h"

class Controller {
private:
    Store               model;
    View                view;
    ClientOrderView     clientOrderView;
    ClientView          clientView;
    ProductView         productView;
    CartView            cartView;

    User*               loggedUser{};
    Cart                cart;


public:
    Controller(Store& store);
    void run();
};


#endif //FSOFT2024_1DC_3_CONTROLLER_H
