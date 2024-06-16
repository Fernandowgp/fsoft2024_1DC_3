//
// Created by nogue on 6/5/2024.
//


#include "../../headers/model/ClientOrder.h"
#include "../../headers/views/Utils.h"
#include "../../exception/headers/InvalidDataException.h"

ClientOrder::ClientOrder(Date date, Client* client, float value) {
    this->date = date;
    this->setClient(client);
    this->setValue(value);
}


void ClientOrder::setClient(Client *pClient) {
    if(pClient != nullptr){
        this->client = pClient;
    }else{
        this->client = nullptr;
        string msg = "ClientOrder : Client = NULL";
        throw InvalidDataException(msg);
    }
}

Client *ClientOrder::getClient() {
    return this->client;
}

ClientOrder &ClientOrder::get() {
    return *this;
}
