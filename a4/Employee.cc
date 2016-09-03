#include "Employee.h"
#include <sstream>

Employee::Employee(int num, string pass)
  :Account(num, pass,2)
{
  //clockIn = 0;
}

string Employee::print()
{
  stringstream theString;
  //time_t timev;
  //clockIn = time(&timev);
  theString << "Welcome Employee!" << endl << "You have now clocked in." << endl;
  return theString.str();
}

float Employee::clockOut()
{
  return 6.9;

}

string Employee::getInfo()
{
  stringstream theString;
  theString << "Employee Number: " << getNum() << endl;
  return theString.str();
}

string Employee::logout()
{
  stringstream theString;
  theString << "GoodBye Employee!" << endl;
  return theString.str();
}
