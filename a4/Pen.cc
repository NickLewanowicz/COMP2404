#include "Pen.h"
#include <sstream>
Pen::Pen(string s, int d, float p, int r)
{
  color = s;
  durability = d;
  setPrice(p);
  setRating(r);
}

string Pen::getColor(){return color;}
int Pen::getDurability(){return durability;}
void Pen::setColor(string f){color = f;}
void Pen::setDurability(int s){durability = s;}

string Pen::print()
{
  stringstream theString;
  theString << " Pen:" << endl;
  theString << "Color:     " << color << endl;
  theString << "Durability:" << durability << endl;
  theString << "Price:     $" << getPrice() << endl;
  theString << "Rating:    " << getRating() << endl;
  return theString.str();
}
