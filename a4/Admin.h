#ifndef ADMIN_H
#define ADMIN_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Account.h"

class Admin: public Account
{
  public:
    Admin(int, string);
    ~Admin();
    string logout();
    string print();
    string getInfo();
  private:
    int lastLogin;
};

#endif
