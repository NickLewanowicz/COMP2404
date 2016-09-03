#include "Course.h"
#include <sstream>

Course::Course(string s, string nu, string na, string i, int e)
{
   subj  = s;
   num   = nu;
   name  = na;
   instr = i;
   enrol = e;
   books = new BookArray();
}

Course::~Course(){
	delete books;
}

string Course::getCode()      { return subj + num; }
string Course::getName()      { return name; }
string Course::getInstr()     { return instr; }
int    Course::getEnrol()     { return enrol; }

int    Course::getNumBooks()  { return books->getSize(); }

void   Course::addBook(Book* b)
{
  books->add(b);
}

void Course::getBook(int num, Book** book){*book = books->getBook(num);}

string   Course::printBooks(){
  stringstream theString;
	for(int i = 0; i < books->getSize(); i++){
		theString << "Title:   " << books->getBook(i)->getTitle() << endl;
		theString << "Auhtor:  " << books->getBook(i)->getAuthors() << endl;
		theString << "ISBN:    " << books->getBook(i)->getISBN() << endl;
		theString << "Edition: " << books->getBook(i)->getEdition() << endl;
		theString << "Year:    " << books->getBook(i)->getYear() << endl;
    theString << "Price:   $" << books->getBook(i)->getPrice() << endl;
    theString << "Rating:   " << books->getBook(i)->getRating() << endl;
	}
  return theString.str();
}

string Course::getInfo(){
  stringstream theString;
  theString << "Course:     " << getCode()  << "  " << getName() << endl;
  theString << "Instructor: " << getInstr()  << endl;
  theString << "Enrolment:  " << getEnrol() << endl;
  theString << "Textbooks:  ";
  if (books->getSize() == 0) {
    theString << "None" << endl;
  }
  else {
    theString << printBooks();
  }
  return theString.str();
}

//bool Course::isLess(Course* a){
//  if(a->getCode() > this->getCode()){
//    return true;
//  }else{
//    return false;
//  }
//}
