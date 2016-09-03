#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

#include <iostream>
#include <string>


class Product
{
  public:
    Product();
    float getPrice();
    void setPrice(float);
    int getRating();
    void setRating(int);
    string getName();
    void setName(string);
    virtual string print();
  private:
    float price;
    int rating;
    string name;
};


#endif
