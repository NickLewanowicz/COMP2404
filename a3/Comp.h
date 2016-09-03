#ifndef COMP_H
#define COMP_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

class Comp: public Product
{
  public:
    Comp(string, string, float, int);
    string getOs();
    void setOs(string);
    string getForm();
    void setForm(string);
    string print();
  private:
    string os;
    string formFactor;
};


#endif
