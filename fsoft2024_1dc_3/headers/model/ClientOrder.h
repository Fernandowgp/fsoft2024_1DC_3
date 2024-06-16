//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_CLIENTORDER_H
#define FSOFT2024_1DC_3_CLIENTORDER_H

#include "Order.h"
#include "Client.h"

class Client;

class ClientOrder : public Order{
private:
    Client* client{};
public:
    ClientOrder() = default;
    ClientOrder(Date date, Client* client, float value);
    void setClient(Client* pClient);
    Client* getClient();
    ClientOrder& get();
};

#endif //FSOFT2024_1DC_3_CLIENTORDER_H
