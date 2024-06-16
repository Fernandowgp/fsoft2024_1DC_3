//
// Created by Luís on 04/06/2024.
//

#ifndef FSOFT2024_1DC_3_MOCKDATA_H
#define FSOFT2024_1DC_3_MOCKDATA_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include "../headers/model/Client.h"
#include "../headers/model/ClientList.h"
#include "../headers/model/CompoStore.h"
#include "../headers/model/Product.h"

using namespace std;

class MockData {
private:
    static void loadMockClients(ClientList& clientList);
    static void loadMockProducts(ProductList& productList);
public:
    static void generateData(CompoStore& compoStore);
};

#endif //FSOFT2024_1DC_3_MOCKDATA_H