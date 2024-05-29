//
// Created by Luís on 26/05/2024.
//

#include <iostream>
#include "../../headers/controllers/Controller.h"
#include "../../headers/model/Store.h"
using namespace std;

Controller::Controller(Store& store){
    this->model = store;
}

void Controller::run(){
    int aux = -1;
    do{
        aux=this->view.mainMenu();
        switch (aux) {
            case 1:
                cout<<"teste1";
                break;
            case 2:
                cout<<"teste1";
                break;
            case 3:
                cout<<"teste1";
                break;
            default:
                break;

        }
    } while (aux!=0);
}