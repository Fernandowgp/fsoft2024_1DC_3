//
// Created by Luís on 26/05/2024.
//

#ifndef FSOFT2024_1DC_3_CONTROLLER_H
#define FSOFT2024_1DC_3_CONTROLLER_H

#include "../views/View.h"
#include "../model/CompoStore.h"
#include "../views/ClientOrderView.h"
#include "../views/ClientView.h"
#include "../views/ProductView.h"
#include "../views/CartView.h"
#include "../model/Cart.h"
#include "../model/Login.h"

using namespace std;

class Controller{
private:
    CompoStore          model;
    View                view;
    ClientOrderView     clientOrderView;
    ClientView          clientView;
    ProductView         productView;
    CartView            cartView;
    Client*             loggedUser{};
    Cart                cart;

    //Guest
    void runGuest();
    void runLogin();
    void runCreateAccount();
    //Client
    void runClient();
    void runProducts();
    void checkOutClient();
    void completeRegistration();
    void runViewAllClientsOrders();
    void runCreateProduct();
    void runEditProduct();
    void runToggleProductAvailability();

    void runClientOrders();
    //Both Client and Manager
    void runCart();
    void runAddToCart();
    void runDeleteFromCart();
    void runViewOrdersFromAClient();
    void login(Client* pClient);
    void logout();

public:
    explicit Controller(CompoStore& CompoStore);
    void run();


};



#endif //FSOFT2024_1DC_3_CONTROLLER_H
