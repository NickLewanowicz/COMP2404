#include "Student.h"
#include "Account.h"
#include <sstream>
Student::Student(int num, string pass)
  :Account(num, pass, 1)
{
  accBalance = 0;
}

float Student::getBalance(){ return accBalance;}

string Student::print()
{
  stringstream theString;
  theString << "Welcome Student!" << endl << "You have $" << accBalance << " remaining balance." << endl;
  return theString.str();
}

void Student::addBalance(float deposit)
{
  accBalance += deposit;
}

string Student::getInfo()
{
  stringstream theString;
  theString << "Student Number: " << getNum() << endl;
  theString << "Balance: " << accBalance  << endl;
  return theString.str();
}

string Student::logout()
{
  stringstream theString;
  theString << "GoodBye student!" << endl;
  return theString.str();
}
