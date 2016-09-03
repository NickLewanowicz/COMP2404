#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

#include <iostream>
#include <string>

#include "defs.h"
#include "Account.h"
#include "Course.h"
#include "DList.h"
#include "Account.h"
#include "Book.h"

class Student: public Account
{
  public:
    Student(int, string);
    ~Student();
    string logout();
    string print();
    string getInfo();
    float getBalance();
    void addBalance(float);

  private:
    float accBalance;
};

#endif
