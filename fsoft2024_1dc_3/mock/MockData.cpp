//
// Created by Luís on 04/06/2024.
//


#include "MockData.h"

void MockData::loadMockClients(ClientList& clientList) {
    int rows = 5;
    int columns = 4;
    string data[rows][columns];

    ifstream file("../data/mockClients.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    for(int row = 0; row < rows; ++row)
    {
        string line;
        getline(file, line);

        stringstream iss(line);

        for (int col = 0; col < columns; ++col)
        {
            string val;
            getline(iss, val, ',');
            data[row][col] = val;
        }
    }
    for(int i = 1; i < rows; ++i){
        Client client(data[i][0], data[i][1], 0);
        clientList.addClient(client);
    }
}

void MockData::loadMockProducts(ProductList(& productList)) {
    int rows = 10;
    int columns = 8;
    string data[rows][columns];

    ifstream file("../data/mockProducts.csv");

    if (!file.is_open()) {
        cout << "File not opened" << endl;
        return;
    }

    for(int row = 0; row < rows; ++row)
    {
        string line;
        getline(file, line);

        stringstream iss(line);

        for (int col = 0; col < columns; ++col)
        {
            string val;
            getline(iss, val, ',');
            data[row][col] = val;
           // cout<<val<<endl; //testing
        }
    }
    for(int i = 1; i < rows; ++i){

        bool available = stoi(data[i][7]) ;
        Product product(stoi(data[i][0]),
                        data[i][1],
                        data[i][2],
                        data[i][3],
                        data[i][4],
                        stoi(data[i][5]),
                        stof(data[i][6]),
                        available);
        productList.add(product);
    }
}

void MockData::generateData(CompoStore& compoStore){
    loadMockClients(compoStore.getClientList());
    loadMockProducts(compoStore.getProductList());
}