#ifndef CALCULATOR_H
#define CALCULATOR_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Product.h"

class Calculator: public Product
{
  public:
    Calculator(bool, bool, float, int);
    bool getScientific();
    void setScientific(bool);
    bool getExam();
    void setExam(bool);
    string print();
  private:
    bool scientific;
    bool examApproved;
};


#endif
