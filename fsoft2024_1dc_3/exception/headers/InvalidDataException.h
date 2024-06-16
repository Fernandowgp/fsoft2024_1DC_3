//
// Created by nogue on 6/4/2024.
//

#ifndef FSOFT2024_1DC_3_INVALIDDATAEXCEPTION_H
#define FSOFT2024_1DC_3_INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>
using namespace std;

class InvalidDataException :public exception{
private:
    string data;
public:
    InvalidDataException(string data);
    //override what function
    const char* what();
};

#endif //FSOFT2024_1DC_3_INVALIDDATAEXCEPTION_H
