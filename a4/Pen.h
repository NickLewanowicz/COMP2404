#ifndef PEN_H
#define PEN_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

class Pen: public Product
{
  public:
    Pen(string, int, float, int);
    string print();
    string getColor();
    void setColor(string);
    int getDurability();
    void setDurability(int);
  private:
    int durability;
    string color;
};


#endif
