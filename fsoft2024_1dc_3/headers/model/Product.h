//
// Created by nogue on 6/5/2024.
//

#ifndef FSOFT2024_1DC_3_PRODUCT_H
#define FSOFT2024_1DC_3_PRODUCT_H

#include <string>

using namespace std;

class Product{
private:
    int ProductID;
    string name;
    string category;
    string description;
    string brand;
    int stock;
    float sellingPrice;
    bool isAvailable;
public:
    Product(int ProductID,
            const string& name,
            const string& description,
            const string& category,
            const string& brand,
            int stock,
            float sellingPrice,
            bool isAvailable);

    void setProductID(const int& ProductID);
    void setProductName(const string& name);
    void setDescription(const string& description);
    void setCategory(const string& category);
    void setBrand(const string& brand);
    void setStock(int stock);
    void setSellingPrice(float sellingPrice);
    void setAvailable();
    void setUnavailable();
    void changeAvailability();

    Product& get();
    const int& getProductID() const;
    const string& getName() const;
    const string& getDescription() const;
    const string& getCategory() const;
    const string& getBrand() const;
    int getStock() const;
    float getSellingPrice() const;
    bool getIsAvailable() const;

    bool operator == (int& ProductID) const;  //Compare if the products are equal through the ProductID
    bool operator == (const Product &obj) const;

};



#endif //FSOFT2024_1DC_3_PRODUCT_H
