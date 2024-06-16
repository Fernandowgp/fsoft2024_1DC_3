//
// Created by Fernando on 29/05/2024.
//

#ifndef MODEL_HEADERS_LOGIN_H
#define MODEL_HEADERS_LOGIN_H

#include <string>
#include "iostream"

using namespace std;

class Login {
protected:
    string username;
    string password;
    string name;

    // Construtor protegido para evitar instanciamento direto
    Login();
    Login(string& pUsername, string& pPassword);

    virtual void setUsername(string& pUsername);

public:
    // Métodos getter
    [[nodiscard]] virtual string getUsername() const;

    virtual string getPassword();

    virtual string getName();

    virtual // Métodos setter
    void setName(string pName);

    virtual void setPassword(string& pPassword);

    // Métodos de autenticação
    bool login(const string& pUsername, const string& pPassword);
    static void logout();
};

#endif //MODEL_HEADERS_LOGIN_H
