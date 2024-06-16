//
// Created by nogue on 6/5/2024.
//


#include "../../headers/model/Product.h"
using namespace std;

Product::Product(int ProductID,
                 const std::string &name,
                 const std::string &description,
                 const std::string &category,
                 const std::string &brand,
                 int stock,
                 float sellingPrice,
                 bool isAvailable){

    setProductName(name);
    setDescription(description);
    setCategory(category);
    setBrand(brand);
    setProductID(ProductID);
    setStock(stock);
    setSellingPrice(sellingPrice);
    if(isAvailable) {
        setAvailable();
    }else{
        setUnavailable();
    }
}

bool Product::operator==(int& ProductID) const {
    if(this->ProductID == ProductID){
        return true;
    }return false;
}

void Product::setProductName(const string &name)
{
    this->name = name;
}

void Product::setDescription(const string &description)
{
    this->description = description;
}

void Product::setCategory(const string &category)
{
    this->category = category;
}

void Product::setBrand(const string &brand)
{
    this->brand = brand;
}

void Product::setProductID(const int &ProductID) {
    this->ProductID = ProductID;
}

void Product::setStock(int stock)
{
    this->stock = stock;
}

void Product::setSellingPrice(float sellingPrice)
{
    this->sellingPrice = sellingPrice;
}

void Product::setAvailable()
{
    this->isAvailable = true;
}

void Product::setUnavailable()
{
    this->isAvailable = false;
}

bool Product::operator==(const Product &obj) const
{
    if (this->getProductID() == obj.getProductID())
        return true;
    return false;
}

float Product::getSellingPrice() const {
    return this->sellingPrice;
}


const int& Product::getProductID() const {
    return this->ProductID;
}

const string &Product::getName() const {
    return this->name;
}

const string &Product::getDescription() const {
    return this->description;
}

const string &Product::getCategory() const {
    return this->category;
}

const string &Product::getBrand() const {
    return this->brand;
}

int Product::getStock() const {
    return this->stock;
}

bool Product::getIsAvailable() const {
    return this->isAvailable;
}

Product &Product::get() {
    return *this;
}

void Product::changeAvailability() {
    if(this->getIsAvailable()){
        this->setUnavailable();
        return;
    }
    this->setAvailable();
}
