#include <iostream>
#include "../../headers/views/View.h"
#include "../../headers/views/Utils.h"

using namespace std;

View::View(){

}

//Menu for all users
int View::menuMain(){
    int op = -1;
    do{
        cout << "\n  -----------------------\n";
        cout << " |       Main Menu       |\n";
        cout << " |                       |\n";
        cout << " | 1 - View Products     |\n";
        cout << " | 2 - Login             |\n";
        cout << " | 3 - Sign up           |\n";
        cout << " | 0 - Exit              |\n";
        cout << "  -----------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 6);
    return op;
}



//Menu for clients
int View::menuClient(){
    int op = -1;
    do{
        cout << "\n  ------------------------------\n";
        cout << " |       Client Menu            |\n";
        cout << " |                              |\n";
        cout << " | 1 - View products            |\n";
        cout << " | 2 - View cart                |\n";
        cout << " | 3 - View orders              |\n";
        cout << " | 4 - Complete registration    |\n";
        cout << " |                              |\n";
        cout << " | 0 - Logout                   |\n";
        cout << "  ------------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 4);
    return op;
}

//Menu for the client to see products and add products to the cart
int View::menuProducts(){
    int op = -1;
    do{
        //ADD LIST OF THE PRODUCTS
        cout << "\n  ---------------------------\n";
        cout << " |       Menu Products       |\n";
        cout << " |                           |\n";
        cout << " | 1 - Add to cart           |\n";
        cout << " | 2 - View cart             |\n";
        cout << " |                           |\n";
        cout << " | 0 - Go back               |\n";
        cout << "  ---------------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 2);
    return op;
}

//Menu for the client to see products and add products to the cart
int View::menuCart(){
    int op = -1;
    do{
        //ADD LIST OF THE PRODUCTS IN CART
        cout << "\n  -----------------------\n";
        cout << " |       Menu Cart       |\n";
        cout << " |                       |\n";
        cout << " | 1 - Delete from cart  |\n";
        cout << " | 2 - Checkout          |\n";
        cout << " |                       |\n";
        cout << " | 0 - Go back           |\n";
        cout << "  -----------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 2);
    return op;
}

int View::menuGuest() {
    int op = -1;
    do{
        cout << "\n  -----------------------\n";
        cout << " |       Main Menu       |\n";
        cout << " |                       |\n";
        cout << " | 2 - Login             |\n";
        cout << " | 3 - Sign up           |\n";
        cout << " |                       |\n";
        cout << " | 0 - Exit              |\n";
        cout << "  -----------------------\n";
        op = Utils::getNumber("Option");
    }while(op < 0 || op > 3 || op == 1);
    return op;
}

