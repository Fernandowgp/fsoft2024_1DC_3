//
// Created by Fernando on 04/06/2024.
//

#ifndef FSOFT2024_1DC_3_MANAGER_H
#define FSOFT2024_1DC_3_MANAGER_H

#include "Client.h"

class Manager {
private:
    string username;
    string password;
public:
    Manager() = default;
    void set(string& pUsername, string& pPassword);
};

#endif //FSOFT2024_1DC_3_MANAGER_H
