//
// Created by Fernando on 29/05/2024.
//

#ifndef MODEL_HEADERS_LOGIN_H
#define MODEL_HEADERS_LOGIN_H

#include <string>
//#include "DuplicateEntryException.h"
#include "iostream"

using namespace std;

class Login {
protected:
    string username;
    string password;
    string name;

    Login();
    Login(string& pUsername, string& pPassword);
    void setUsername(string& pUsername);

public:
    virtual string getUsername() const;
    void setName(string pName);
    void setPassword(string& pPassword);

    string getPassword();
    string getName();

    bool login(const string& pUsername, const string& pPassword);
    void logout();
};

#endif //MODEL_HEADERS_LOGIN_H
