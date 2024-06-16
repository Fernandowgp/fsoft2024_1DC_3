//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_CLIENTORDERVIEW_H
#define FSOFT2024_1DC_3_CLIENTORDERVIEW_H


#include "../model/ClientOrder.h"
#include "../model/ClientOrderList.h"
#include "View.h"



class ClientOrderView {
public:
    void printClientOrdersByClient(ClientOrderList& clientOrders, Client& client);
    void printAllClientOrders(ClientOrderList& clientOrders);
    void orderPlaced();
    void thereAreNoOrders();
};



#endif //FSOFT2024_1DC_3_CLIENTORDERVIEW_H
