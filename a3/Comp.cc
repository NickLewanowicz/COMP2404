#include "Comp.h"
#include <sstream>
Comp::Comp(string op, string form, float price, int rate)
{
  os = op;
  formFactor = form;
  setPrice(price);
  setRating(rate);
}

string Comp::getOs(){return os;}
string Comp::getForm(){return formFactor;}
void Comp::setOs(string f){os = f;}
void Comp::setForm(string s){formFactor = s;}

string Comp::print()
{
  stringstream theString;
  theString << " Computer:" << endl;
  theString << "Operating system: " << os << endl;
  theString << "Form Factor:      " << formFactor << endl;
  theString << "Price:            $" << getPrice() << endl;
  theString << "Rating:           " << getRating() << endl;
  return theString.str();
}
