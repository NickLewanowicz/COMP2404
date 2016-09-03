#include <iostream>
#include <string>
using namespace std;

#include "BookArray.h"

BookArray::BookArray()
{
  size = 0;
	books = new Book*[1];
}

BookArray::~BookArray(){
  for(int i = 0;i<size;i++){
		delete books[i];
  }
  delete[] books;
}

int   BookArray::getSize()        { return size; }
Book*  BookArray::getBook(int i)   { return books[i]; }

void BookArray::add(Book* book)
{
  ++size;

  Book** tempList = new Book*[size];
  for (int i = 0; i<size - 1; ++i){
    tempList[i] = books[i];
  }

  delete[] books;
  books = tempList;

  books[size - 1] = book;
}
// comment 
