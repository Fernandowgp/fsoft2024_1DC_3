//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_CLIENTVIEW_H
#define FSOFT2024_1DC_3_CLIENTVIEW_H

#include "../model/Client.h"
#include "../model/ClientList.h"

class ClientView {
public:
    string getUsername();
    string getPassword();
    string getName();
    void invalidUsername();
    void incorrectPassword();
    void printClientListManager(list<Client>& clients, const string& listTitle);
    void clientNotFound();
};

#endif //FSOFT2024_1DC_3_CLIENTVIEW_H
