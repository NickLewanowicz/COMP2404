#include "Book.h"
#include <sstream>
Book::Book(string t, string a, string i, int e, int y, float p, int s)
     :Product()
{
   title   = t;
   authors = a;
   isbn    = i;
   edition = e;
   year    = y;
   setPrice(p);
   setRating(s);
}

string Book::getTitle()    { return title; }
string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }

string Book::print()
{
  stringstream theString;
    theString << " TextBook:" << endl;
  theString << "Title:   " << title << endl;
  theString << "Auhtor:  " << authors << endl;
  theString << "ISBN:    " << isbn << endl;
  theString << "Edition: " << edition << endl;
  theString << "Year:    " << year << endl;
  theString << "Price:   $" << getPrice() << endl;
  theString << "Rating:   " << getRating() << endl;
  return theString.str();
}

string Book::getInfo()
{
  stringstream theString;
  theString << " TextBook:" << endl;
  theString << "Title:   " << title << endl;
  theString << "Auhtor:  " << authors << endl;
  theString << "ISBN:    " << isbn << endl;
  theString << "Edition: " << edition << endl;
  theString << "Year:    " << year << endl;
  theString << "Price:   $" << getPrice() << endl;
  theString << "Rating:   " << getRating() << endl;
  return theString.str();

}
