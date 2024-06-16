//
// Created by nogue on 6/5/2024.
//

#include "../../headers/model/ClientOrderList.h"

ClientOrderList::ClientOrderList() {

}

void ClientOrderList::add(const ClientOrder &pClientOrder) {
    this->clientOrders.push_back(pClientOrder);
}


void ClientOrderList::setClients(ClientList *clients) {
    this->clients = clients;
}

void ClientOrderList::setProducts(ProductList *products) {
    this->products = products;
}

ClientOrderList ClientOrderList::getClientOrders() {
    return {};
}

ClientOrderList ClientOrderList::getClientOrdersByClient(Client *pClient, ClientOrderList& modelClientOrderList) {
    ClientOrderList returnClientOrderList;
    auto it = modelClientOrderList.clientOrders.begin();
    for (; it != modelClientOrderList.clientOrders.end(); ++it){
        if((it->getClient()) == pClient){
            ClientOrder tempClientOrder = it->get();
            returnClientOrderList.add(tempClientOrder);
        }
    }

    return returnClientOrderList;
}

list<ClientOrder> ClientOrderList::getAll() {
    list<ClientOrder> newClientOrderList (this->clientOrders);
    return newClientOrderList;
}

bool ClientOrderList::hasClientMadeOrders(Client *pClient, ClientOrderList &modelClientOrderList) {
    bool areThereOrders = false;

    auto it = modelClientOrderList.clientOrders.begin();
    for (; it != this->clientOrders.end(); ++it){

        if((it->getClient()) == pClient){
            areThereOrders = true;
        }
    }
    return areThereOrders;
}

int ClientOrderList::getSize(ClientOrderList &clientOrderList) {
    int i = 0;
    auto it = clientOrderList.clientOrders.begin();
    for(; it != clientOrderList.clientOrders.end(); ++it){
        ++i;
    }
    return i;
}