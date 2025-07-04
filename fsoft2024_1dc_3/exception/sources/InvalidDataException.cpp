//
// Created by nogue on 6/4/2024.
//


#include "../headers/InvalidDataException.h"


InvalidDataException::InvalidDataException(string data){
    this->data = data;
}

const char* InvalidDataException::what(){
    string msg = "Error: ["+ data + "] is not valid!!";
    return msg.c_str();
}
