//
// Created by Fernando on 04/06/2024.
//

#ifndef FSOFT2024_1DC_3_CLIENT_H
#define FSOFT2024_1DC_3_CLIENT_H

#include <string>
#include "Login.h"
#include <iostream>

using namespace std;

class Client : public Login {
private:

    // Construtor privado para prevenir instanciamento sem parâmetros
    Client();

public:
    // Construtor público para inicializar objetos
    Client(string &pUsername, string &pPassword, int permission);

    explicit Client(int permission);

    // Métodos getter e setter adicionais
    void setPermission();

    // Outros métodos
    bool doesPasswordMatch(string &password);
    bool operator==(const Client &) const;
    bool operator==(string& username) const;

    // Classe amiga
    friend class MockData;

    // Removido override
    void setUsername(string &pUsername);
    void setPassword(string &pPassword);
    string getPassword();
    string getName();
    [[nodiscard]] string getUsername() const;
    void setName(string pName);

    int permission{};
};

#endif //FSOFT2024_1DC_3_CLIENT_H
