#include "Professor.h"
#include <sstream>

Professor::Professor(int num, string pass)
  :Account(num, pass, 3)
{

}


string Professor::print()
{
  stringstream theString;
  theString << "Welcome Professor!" << endl;
  return theString.str();
}

string Professor::getInfo()
{
  stringstream theString;
  theString << "Professor Number: " << getNum() << endl;
  return theString.str();
}

string Professor::logout()
{
  stringstream theString;
  theString << "GoodBye Professor!" << endl;
  return theString.str();
}
