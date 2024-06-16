//
// Created by Fernando on 04/06/2024.
//

#include "../../headers/model/Client.h"

Client::Client(string &pUsername, string &pPassword, int permission)
        : Login(pUsername, pPassword), permission(permission) {}

Client::Client(int permission) : Login(), permission(permission) {}

void Client::setPermission() {
    // Implementation of the method to set permission
}

bool Client::doesPasswordMatch(string &password) {
    return this->password == password;
}

bool Client::operator==(const Client &other) const {
    return this->username == other.username;
}

bool Client::operator==(string &username) const {
    return this->username == username;
}

void Client::setUsername(string &pUsername) {
    this->username = pUsername;
}

void Client::setPassword(string &pPassword) {
    this->password = pPassword;
}

string Client::getPassword() {
    return this->password;
}

string Client::getName() {
    return this->name;
}

string Client::getUsername() const {
    return this->username;
}

void Client::setName(string pName) {
    this->name = pName;
}
