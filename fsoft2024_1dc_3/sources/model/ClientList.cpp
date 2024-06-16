//
// Created by nogue on 6/4/2024.
//


#include "../../headers/model/ClientList.h"

list<Client>::iterator ClientList::searchByUsername(std::string &username) {
    auto it= this->clients.begin();
    for (;it != this->clients.end(); ++it) {
        if((*it) == username){
            return it;
        }
    }
    return it;
}

list<Client> ClientList::getAll() {
    list<Client> newClientList (this->clients);
    return newClientList;
}

Client* ClientList::getByUsername(std::string &username) {
    auto it = searchByUsername(username);
    if(it != this->clients.end()){
        return &(*it);
    }
    return nullptr;
}

void ClientList::addClient(Client &client) {
    string username= client.getUsername();
    auto it= searchByUsername(username);
    if(it == this->clients.end()){
        this->clients.push_back(client);
    }else {
        string msg = "Client: " + username;
        //throw DuplicateEntryException(msg);
    }
}