//
// Created by nogue on 6/5/2024.
//

#include <iostream>
#include "../../headers/views/ClientView.h"
#include "../../headers/views/Utils.h"
#include "../../exception/headers/InvalidDataException.h"
#include "../../headers/views/View.h"

using namespace std;


string ClientView::getUsername() {
    return Utils::getString("Please enter your username");
}

string ClientView::getPassword() {
    return Utils::getString("Please enter your password - UNSECURE");
}

void ClientView::invalidUsername() {
    cout << "Invalid Username";
}

void ClientView::incorrectPassword() {
    cout << "Incorrect Password";
}



void ClientView::printClientListManager(list<Client>& clients, const string& listTitle) {


    cout << listTitle << endl;
    cout << left <<"Name";
    cout << left <<"Username";
    cout << endl;

    for (Client client : clients) {
        cout << left<< client.getName();
        cout << left<< client.getUsername();

        cout << endl;
    }
}

string ClientView::getName() {
    string name;
    int spaceCount;
    do{
        spaceCount = 0;
        name = Utils::getString("Please enter your first and last names");
        for(int i = 0; name[i] != '\0'; i++){
            if(name[i] == ' ')
                spaceCount++;
        }
        if(spaceCount == 0)
            cout << "Too few words" << endl;
        if(spaceCount > 1)
            cout << "Too many words" << endl;
    }while(spaceCount !=1);
    return  name;
}

void ClientView::clientNotFound() {
    cout << "Client not found";
}