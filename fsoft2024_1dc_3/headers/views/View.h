//
// Created by Luís on 26/05/2024.
//

#ifndef FSOFT2024_1DC_3_VIEW_H
#define FSOFT2024_1DC_3_VIEW_H
#include <string>

using namespace std;

class View {
    public:
        //Menus for all users
        View();
        int menuMain();
        //Menus for clients
        int menuClient();
        int menuProducts();
        int menuCart();
        int menuGuest();
};


#endif //FSOFT2024_1DC_3_VIEW_H