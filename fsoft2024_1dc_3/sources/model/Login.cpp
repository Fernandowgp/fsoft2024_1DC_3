//
// Created by Fernando on 29/05/2024.
//

#include <utility>

#include "../../headers/model/Login.h"

// Construtores
Login::Login() : username(""), password(""), name("") {}

Login::Login(string& pUsername, string& pPassword)
        : username(pUsername), password(pPassword), name("") {}

// Métodos setter
void Login::setUsername(string& pUsername) {
    username = pUsername;
}

void Login::setPassword(string& pPassword) {
    password = pPassword;
}

void Login::setName(string pName) {
    name = std::move(pName);
}

// Métodos getter
string Login::getUsername() const {
    return username;
}

string Login::getPassword() {
    return password;
}

string Login::getName() {
    return name;
}

// Métodos de login e logout
bool Login::login(const string& pUsername, const string& pPassword) {
    if (username == pUsername && password == pPassword) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid username or password." << endl;
        return false;
    }
}

void Login::logout() {
    cout << "Logged out successfully!" << endl;
}
