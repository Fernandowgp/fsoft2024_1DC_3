//
// Created by nogue on 6/4/2024.
//

#ifndef FSOFT2024_1DC_3_CLIENTLIST_H
#define FSOFT2024_1DC_3_CLIENTLIST_H

#include <list>
#include "Client.h"

class ClientList {
private:
    list<Client> clients;

    list<Client>::iterator searchByUsername(string& username);

public:
    list<Client> getAll();
    Client* getByUsername(string& username);
    void addClient(Client& client);


};


#endif //FSOFT2024_1DC_3_CLIENTLIST_H
