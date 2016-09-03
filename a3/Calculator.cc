#include "Calculator.h"
#include <sstream>
Calculator::Calculator(bool s, bool e, float p, int r)
{
  scientific = s;
  examApproved = e;
  setPrice(p);
  setRating(r);
}

bool Calculator::getScientific(){return scientific;}
bool Calculator::getExam(){return examApproved;}
void Calculator::setScientific(bool f){scientific = f;}
void Calculator::setExam(bool s){examApproved = s;}

string Calculator::print()
{
  string sci = "No", appr = "No";
  if(scientific){sci = "Yes";}
  if(examApproved){appr = "Yes";}
  stringstream theString;
  theString << " Calculator:" << endl;
  theString << "Scientific:     " << sci << endl;
  theString << "Exam approved:  " << appr << endl;
  theString << "Price:          $" << getPrice() << endl;
  theString << "Rating:         " << getRating() << endl;
  return theString.str();
}
