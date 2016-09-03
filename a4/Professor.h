#ifndef Professor_H
#define Professor_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Account.h"
#include "Book.h"

class Professor: public Account
{
public:
  Professor(int, string);
  string logout();
  string print();
  string getInfo();
};

#endif
