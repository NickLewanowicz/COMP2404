#include <iostream>
#include <string>
using namespace std;

#include "ProductArray.h"

ProductArray::ProductArray()
{
  size = 0;
	products = new Product*[1];
}

ProductArray::~ProductArray(){
  for(int i = 0;i<size;i++){
		delete products[i];
  }
  delete[] products;
}

int   ProductArray::getSize()        { return size; }
Product*  ProductArray::getProduct(int i)   { return products[i]; }

void ProductArray::add(Product* product)
{
  ++size;

  Product** tempList = new Product*[size];
  for (int i = 0; i<size - 1; ++i){
    tempList[i] = products[i];
  }

  delete[] products;
  products = tempList;

  products[size - 1] = product;
}

void ProductArray::removeProduct(Product* product){
  int i = 0;
  for(i=0; i<size;i++){
    if(products[i] == product){
      if (size == 1){
        std::cout << "Removing last element" << std::endl;
        delete[] products;
        products = new Product*[1];
        size = 0;
      }else{
        std::cout << "Size: " << size << std::endl;
        Product** tempList = new Product*[size-1];
        for (int j = 0; j<size-1; j++){
          if(j<i){
            tempList[j] = products[j];
          }else{
            tempList[j] = products[j+1];
          }
        }
        size--;
        delete[] products;
        products = tempList;
      }
      return;
    }
  }
}



void ProductArray::print(){
  for (int i = 0; i<size; ++i){
    cout << "Product #" << i +1;
    cout << products[i]->print() << endl;
  }
}
// comment
