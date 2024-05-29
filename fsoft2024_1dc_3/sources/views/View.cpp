#include <iostream>
#include "../../headers/views/View.h"
#include "../../headers/views/Utils.h"
using namespace std;

View::View() {}

int View::mainMenu() {
    int aux = -1;
    do{
        cout<<"\n\n********** CompoStore **********\n";
        cout<<"1 - View Products\n";
        cout<<"2 - View Cart\n";
        cout<<"3 - View orders\n";
        cout<<"\n";
        cout<<"\n0 - Exit\n";
        aux = Utils::getNumber("Option");
    }while(aux != 0);
    return aux;
}