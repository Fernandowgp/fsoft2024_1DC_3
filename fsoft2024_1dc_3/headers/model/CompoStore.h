//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_COMPOSTORE_H
#define FSOFT2024_1DC_3_COMPOSTORE_H

#include <string>
#include "ClientList.h"
#include "ClientOrderList.h"
#include "Manager.h"

using namespace std;

class CompoStore{
private:
    string name;
    Manager manager;
    ClientList clients;
    ClientOrderList clientOrders;
    ProductList products;
public:
    CompoStore();
    CompoStore(const string& name);
    string& getName();
    void setManager(string pUsername, string pPassword);

    //Manager getManager();
    ClientList& getClientList();
    ClientOrderList& getClientOrderList();
    ProductList& getProductList();
    void setDataForConsistency();
    Client* getManager();
};



#endif //FSOFT2024_1DC_3_COMPOSTORE_H
