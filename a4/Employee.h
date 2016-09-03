#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Account.h"

class Employee: public Account
{
  public:
    Employee(int, string);
    ~Employee();
    bool login(string);
    string logout();
    string print();
    string getInfo();
    float clockOut();
  private:
    //double clockIn;
};

#endif
