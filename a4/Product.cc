#include "Product.h"

Product::Product()
{
  price = 0;
  rating = 0;
}

float Product::getPrice(){return price;}
int Product::getRating(){return rating;}
void Product::setPrice(float f){price = f;}
void Product::setRating(int s){rating = s;}

string Product::print()
{
  return "Not Working";
}
