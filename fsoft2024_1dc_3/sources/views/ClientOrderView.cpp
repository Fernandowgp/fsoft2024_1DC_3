//
// Created by nogue on 6/5/2024.
//

#include "../../headers/views/ClientOrderView.h"
#include "../../headers/views/Utils.h"

void ClientOrderView::orderPlaced() {
    cout << "Order placed!" << endl;
}

void ClientOrderView::printClientOrdersByClient(ClientOrderList &clientOrders, Client &client) {
    cout <<"Orders placed by " << client.getName() << endl;


    Client* clientPtr = &client;
    list<ClientOrder> tempClientOrders = clientOrders.getClientOrdersByClient(clientPtr, clientOrders).getAll();
    auto it = tempClientOrders.begin();
    for (int i = 1; it != tempClientOrders.end(); ++it, ++i){
        cout <<"Order number #";
        cout <<i<<endl;
        cout <<"Date: ";
        cout <<it->getDate()<<endl;
        cout <<"Value: ";
        cout <<it->getValue() <<"€"<< endl;
    }
}

void ClientOrderView::printAllClientOrders(ClientOrderList &clientOrders) {
    cout << "Clients' orders." << endl;
    cout <<"#";
    cout <<"Username";
    cout <<"Date";
    cout <<"Value" << endl;

    list<ClientOrder> tempClientOrders = clientOrders.getAll();
    auto it = tempClientOrders.begin();
    for (int i = 1; it != tempClientOrders.end(); ++it, ++i){
        cout << i;
        cout << it->getClient()->getUsername();
        cout << it->getDate();
        cout << it->getValue() << endl;
    }
}

void ClientOrderView::thereAreNoOrders() {
    cout << "No orders to display.\n";
}
