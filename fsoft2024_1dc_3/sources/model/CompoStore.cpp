//
// Created by nogue on 6/5/2024.
//

#include "../../headers/model/CompoStore.h"


using namespace std;

CompoStore::CompoStore() {
    setDataForConsistency();
}

CompoStore::CompoStore(const string &name) {
    this->name = name;
    setDataForConsistency();
}

string &CompoStore::getName() {
    return name;
}

ClientList &CompoStore::getClientList() {
    return this->clients;
}

ClientOrderList &CompoStore::getClientOrderList() {
    return this->clientOrders;
}



ProductList &CompoStore::getProductList() {
    return this->products;
}

void CompoStore::setDataForConsistency() {
    this->clientOrders.setClients(&this->clients);
    this->clientOrders.setProducts(&this->products);

}

void CompoStore::setManager(string pUsername, string pPassword) {
    this->manager.set(pUsername,pPassword);
}

Client *CompoStore::getManager() {
    Client* user = (Client*)&this->manager;
    return user;
}
