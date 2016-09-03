#include "Admin.h"
#include <sstream>


Admin::Admin(int num, string pass)
: Account(num,pass,4)
{
  lastLogin = 0;
}

string Admin::print()
{
  stringstream theString;
  if(lastLogin != 0){
    theString << "Welcome Admin!" << endl;
  }else{
    theString << "Welcome Admin!" << endl << "This is your first login!" << endl;
    lastLogin = 1;
  }
  return theString.str();
}

string Admin::logout()
{
  stringstream theString;
  theString << "GoodBye Admin!" << endl;
  return theString.str();
}

string Admin::getInfo()
{
  stringstream theString;
  theString << "Admin: " << getNum() << endl;
  return theString.str();
}
