//
// Created by Luís on 26/05/2024.
//

#include "../../headers/views/Utils.h"
#include <iostream>
#include <limits>
using namespace std;



int Utils::getNumber(const string&  label){
    int number;
    bool flag = false;
    do{
        cout<<label<<": ";
        flag = false;
        cin >> number;
        if(cin.fail()){
            cout << "Not a number, please enter a number" << endl;
            cin.clear(); //corrects stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            flag = true;
        }
    }while(flag == true);
    cin.clear(); //corrects stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return number;
}