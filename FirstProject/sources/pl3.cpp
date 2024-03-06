//
// Created by Fernando on 06/03/2024.
//

#include <iostream>
#include "pl3.h"
using namespace std;
void printArray(int *arr, int n){
    for(int* ptr = arr; ptr < arr + n; ptr++){
        cout << ptr - arr<< ": " << *ptr << endl;
    }
}
int getPositiveNumber(){
    int value = 0;
    do{
        cout<<"Enter a positive number:";
        cin >> value;
    }while(value < 0);
    return value;
}
void fillInArray(int *arr, int n){
    for(int* ptr = arr; ptr < arr + n; ptr++){
        *ptr = getPositiveNumber();
    }
}
