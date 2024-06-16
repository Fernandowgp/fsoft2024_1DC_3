//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_CLIENTORDERLIST_H
#define FSOFT2024_1DC_3_CLIENTORDERLIST_H

#include "ClientOrder.h"
#include "ClientList.h"
#include "ProductList.h"
#include <list>

using namespace std;

class ClientList;
class ClientOrder;

class ClientOrderList{
private:
    list<ClientOrder> clientOrders;
    ClientList* clients;
    ProductList* products;
public:
    ClientOrderList();
    int getSize(ClientOrderList& clientOrderList);
    list<ClientOrder> getAll();
    void add(const ClientOrder& pClientOrder);
    ClientOrderList getClientOrders();
    ClientOrderList getClientOrdersByClient(Client* pClient, ClientOrderList& modelClientOrderList);
    bool hasClientMadeOrders(Client* pClient, ClientOrderList& modelClientOrderList);
    void setClients(ClientList* clients);
    void setProducts(ProductList* products);

};

#endif //FSOFT2024_1DC_3_CLIENTORDERLIST_H
