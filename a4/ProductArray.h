#ifndef PRODUCT_ARRAY_H
#define PRODUCT_ARRAY_H

#include "Product.h"

class ProductArray
{
  public:
    ProductArray();
    ~ProductArray();
    void add(Product*);
    Product* getProduct(int);
    void removeProduct(Product*);
    int  getSize();
    void print();
  private:
    int  size;
    Product** products;
};

#endif
