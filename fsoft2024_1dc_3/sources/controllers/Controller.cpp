//
// Created by Luís on 26/05/2024.
//

#include <iostream>
#include "../../headers/controllers/Controller.h"
#include "../../headers/model/Store.h"
#include "../../headers/model/Login.h"

using namespace std;

Controller::Controller(CompoStore& CompoStore){
    this->model = CompoStore;
}

void Controller::run(){
    int aux = -1;
    do{
        aux=this->view.menuMain();
        switch (aux) {
            case 1:
                runGuest();
                break;
            case 2:
                runLogin();
                break;
            case 3:
                runCreateAccount();
                break;
            case 4:
                runCart();
                break;
            case 5:
                runAddToCart();
                break;
            default:
                break;
        }
    } while (aux!=0);
}

void Controller::runGuest() {
    list<Product> products = this->model.getProductList().getAvailable().getAll();
    this->productView.printProductListClient(products, "Product List");
    int op = -1;
    do{
        op = this->view.menuGuest();
        switch(op){
            case 2:
                runLogin(); //2 - Login
                break;
            case 3:
                runCreateAccount(); //3 - Sign up
                break;
            default:
                break;
        }
    }while(op != 0 );
}

void Controller::runLogin() {
    //Username input
    string username = this->clientView.getUsername();
    ClientList &clientList = this->model.getClientList();
    Client *tempClient = clientList.getByUsername(username);

    //Checking if user exists
    if (tempClient == nullptr) {
        this->clientView.invalidUsername();
        return;
    }
    string password = this->clientView.getPassword();

    //Checking if password matches
    if (tempClient->doesPasswordMatch(password)) {
        this->login((Client *) tempClient);
        cout << "Login Successful";
        runClient();
    } else {
        this->clientView.incorrectPassword();
    }
}

void Controller::runCreateAccount() {
    ClientList &clientList = this->model.getClientList();
    string username = this->clientView.getUsername();
    if (clientList.getByUsername(username) != nullptr) {
        cout << "Username already taken.";
        return;
    }
    int permission = 0;
    string password = this->clientView.getPassword();
    Client newClient(username, password, 0);
    clientList.addClient(newClient);
}

void Controller::runClient() {
    int op = -1;
    auto *loggedClient = (Client *) this->loggedUser;
    ClientOrderList &clientOrderList = this->model.getClientOrderList();
    do {
        op = this->view.menuClient();
        switch (op) {
            case 1:
                runProducts(); //1 - View products
                break;
            case 2:
                runCart(); //2 - View cart
                break;
            case 3:
                if (clientOrderList.hasClientMadeOrders(loggedClient, clientOrderList)) {
                    runClientOrders(); //3 - View orders
                } else {
                    cout << "Client has not made any orders.";
                }
                op = -1;
                break;
            case 4: //4 - Complete registration
                completeRegistration();
                break;
            default:
                break;
        }
    } while (op != 0);
    logout();
}






void Controller::runViewAllClientsOrders() {
    ClientOrderList modelClientOrderList = this->model.getClientOrderList();

    //Checking if there are any orders placed by clients
    if (this->model.getClientOrderList().getSize(modelClientOrderList) == 0) {
        this->clientOrderView.thereAreNoOrders();
        return;
    }

    this->clientOrderView.printAllClientOrders(modelClientOrderList);
}

void Controller::runViewOrdersFromAClient() {
    string clientUsername;
    Client *client;
    ClientOrderList modelClientOrderList = this->model.getClientOrderList();
    if (loggedUser->getUsername() == this->model.getManager()->getUsername()) {
        clientUsername = Utils::getString("Insert the username of the client.");
        client = this->model.getClientList().getByUsername(clientUsername);
        if (client == nullptr) {
            this->clientView.clientNotFound();
            return;
        }
        this->clientOrderView.printClientOrdersByClient(modelClientOrderList, *client);
    }
}

void Controller::runCart() {
    list<Product> cartProducts = this->cart.getProducts();

    //Checking if cart has any product
    if (this->cart.getValue() == 0) {
        this->cartView.empty();
        return;
    }

    cout << "Cart value: " << this->cart.getValue() << endl;
    this->cartView.printCartClient(cartProducts);
    int op = -1;
    do {
        op = this->view.menuCart();
        switch (op) {
            case 1: runDeleteFromCart(); // 1 - Delete from cart
                if (this->cart.getValue() == 0) {
                    op = 0;
                    break;
                }
                cartProducts = this->cart.getProducts();
                this->cartView.printCartClient(cartProducts);
                break;
            case 2: // 2 - Checkout
                if (this->cart.getValue() == 0) {
                    this->cartView.empty();
                    break;
                }
                checkOutClient();
                if (this->cart.getValue() == 0) {
                    op = 0;
                    break;
                }
                break;
            default:
                break;
        }
    } while (op != 0);
}

void Controller::runClientOrders() {
    ClientOrderList tempClientOrderList = this->model.getClientOrderList();
    this->clientOrderView.printClientOrdersByClient(tempClientOrderList, *(Client *) loggedUser);
}

void Controller::login(Client* pClient) {
    this->loggedUser = pClient;
}

void Controller::logout() {
    if (this->loggedUser == nullptr) {
        cout << "No account is logged in";
        return;
    }
    this->loggedUser = nullptr;
    cout << "Logout successful";
    this->cart.reset();
}

void Controller::runProducts() {
    int op = -1;
    ProductList *modelProductListPointer = &this->model.getProductList();
    ProductList availableProductList = modelProductListPointer->getAvailable();
    list<Product> clientProducts = availableProductList.getAll();
    list<Product> allProducts = modelProductListPointer->getAll();

    this->productView.printProductListClient(clientProducts, "Products List:");


    do {
        op = this->view.menuProducts();
        switch (op) {
            case 1:
                this->productView.printProductListClient(clientProducts, "Products List: "); //1 - Add to carts
                runAddToCart();
                break;
            case 2: //2 - View cart
                if (this->cart.getValue() == 0) {
                    this->cartView.empty();
                    op = -1;
                    break;
                }
                runCart();

                op = 0;
                break;
            default:
                break;
        }
    } while (op != 0);
}

void Controller::runCreateProduct() {
    ProductList &productList = this->model.getProductList();
    int ProductID = this->productView.getProductID();
    if (productList.get(ProductID) != nullptr) {
        return;
    }
    Product product = this->productView.getProduct(ProductID);
    productList.add(product);
}

void Controller::runEditProduct() {
    ProductList &productList = this->model.getProductList();
    int ProductID = this->productView.getProductID();
    if (productList.get(ProductID) == nullptr) {
        this->productView.invalidProductID();
        return;
    }
    Product tempProduct = this->productView.getProduct(ProductID);
    productList.edit(tempProduct.getName(), tempProduct.getDescription(),
                     tempProduct.getCategory(), tempProduct.getBrand(),
                     tempProduct.getProductID(), tempProduct.getStock(),
                     tempProduct.getSellingPrice(), tempProduct.getIsAvailable());
}

void Controller::runToggleProductAvailability() {
    int ProductID = this->productView.getProductID();
    ProductList &modelProductList = this->model.getProductList();
    if (modelProductList.get(ProductID) == nullptr) {
        this->productView.invalidProductID();
        return;
    }
    Product *product = modelProductList.get(ProductID);
    ProductList *cartProductList = this->cart.getProductList();
    modelProductList.changeAvailability(product, cartProductList);
}

void Controller::runAddToCart() {
    ProductList *modelProductListPointer = &this->model.getProductList();
    ProductList *cartProductListPointer = &this->cart.getProductListRef();
    ProductList availableProductList = modelProductListPointer->getAvailable();
    int ProductID, stockStore, stockCart;

    Product *productInCartPointer, *productInStorePointer;

    ProductID = this->productView.getProductID();
    Product *product;

    product = availableProductList.get(ProductID);

    if (product == nullptr) {
        this->productView.invalidProductID();
        return;
    }

    productInStorePointer = modelProductListPointer->get(ProductID);
    stockStore = productInStorePointer->getStock();
    productInCartPointer = cartProductListPointer->get(ProductID);

    if (!product->getIsAvailable()) {
        this->productView.productUnavailable();
        return;
    }


    if (productInCartPointer == nullptr) {
        stockCart = 0;
        this->cart.add(*product);
        productInCartPointer = cartProductListPointer->get(ProductID);
    } else {
        stockCart = productInCartPointer->getStock();
    }

    productInCartPointer->setStock((stockCart + 1));
    this->cart.updateValueClient();
}



void Controller::runDeleteFromCart() {
    Product *tempProduct;
    int ProductID, stockStore;

    if (this->cart.getValue() == 0) {
        this->cartView.empty();
        return;
    }
    ProductID = this->productView.getProductID();
    tempProduct = this->model.getProductList().get(ProductID);
    if (tempProduct == nullptr) {
        this->productView.invalidProductID();
        return;
    }
    if (this->cart.getProductList()->get(ProductID) == nullptr) {
        this->productView.productUnavailable();
        return;
    }

    this->cart.removeProduct(*tempProduct);

}

void Controller::checkOutClient() {
    ClientOrderList &modelClientOrderList = this->model.getClientOrderList();

    //Checking if client has full profile
    if (loggedUser->getName().empty() == 0) {
        completeRegistration();
    }

    ClientOrder clientOrder = this->cart.getClientOrder((Client *) loggedUser);
    modelClientOrderList.add(clientOrder);
    this->clientOrderView.orderPlaced();
    this->cart.reset();
}

void Controller::completeRegistration() {
    if (loggedUser->getName().empty()) {
        loggedUser->setName(this->clientView.getName());
    }
    if (loggedUser->getName().empty() != 0) {
        cout << "Profile complete!";
    }
}