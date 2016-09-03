#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
  view = new UImanager();
  courses = new DList();
  productArr = new ProductArray();
}

BMScontrol::~BMScontrol(){
  delete  view;
  delete  courses;
	delete  productArr;
}

void BMScontrol::launch()
{
  int    choice;
  Course* course;
  Book* book;
  Product* product;

  while (1) {
    choice = -1;
    course = 0;
    book = 0;
    product = 0;
    view->mainMenu(&choice);
    if (choice == 0) {
      break;
    }
    else if (choice == 1) {
      view->subMenu(&choice);
    }
    else if (choice == 2) {
      view->subMenu(&choice);
    }
    else if (choice == 3) {
      cout << courses->forward() << endl;
      cout << courses->backward() << endl;
      cout << (*courses) << endl;
    }
    else if (choice == 4) {
      view->addTextbook(courses, &course);
      view->getTextbookData(&book);
      course->addBook(book);
      Product* product = book;
      productArr->add(product);
    }
    else if (choice == 5) {
      view->listCourseBooks(courses);
    }
    else if (choice == 6) {
      view->subMenu(&choice);
    }
    else if (choice == 7) {
      productArr->print();
    }
    //Submenu First digit signifies the first option selected from main Menu
            //Second digit signifies the second option they picked from the sub Menu
    if (choice == 11) {
      addCourse(courses);
    } else if (choice == 12){
      addCourses(courses);
    } else if (choice == 21){
      removeCourse(courses);
    } else if (choice == 22){
      removeCourses(courses);
    } else if (choice == 61){
      view->addPen(productArr, &product);
      productArr->add(product);
    } else if (choice == 62){
      view->addCalculator(productArr, &product);
      productArr->add(product);
    } else if (choice == 63){
      view->addComp(productArr, &product);
      productArr->add(product);
    } else if (choice == 64){
      view->addBook(productArr, &product);
      productArr->add(product);
    }
    view->pause();
  }
}

void BMScontrol::addCourse(DList* arr)
{
  Course* course;
  view->getCourseData(&course);
  //arr->add(course);
  (*arr) += course;
}

void BMScontrol::addCourses(DList* arr)
{
  DList* tempArr = new DList();
  Course* course;
  string stop;
  while(1){
    view->getCourseData(&course);
    (*tempArr) += course;
    view->arrayInput(&stop);
    if(stop == "n"){break;}
  }
  (*arr)+=tempArr;
  delete tempArr;
}

void BMScontrol::removeCourses(DList* arr)
{
  DList* tempArr = new DList();
  string stop;
  string code;
  while(1){
    Course* course;
    Book* book=0;
    view->validCourse(arr,&course);
    int num = course -> getNumBooks();
    for(int i=1; i<=num; i++){
      course -> getBook(i,&book);
      if(book != 0){productArr->removeProduct(book);}
    }
    (*tempArr) += course;
    view->arrayInput(&stop);
    if(stop == "n"){break;}
  }
  (*arr)-=tempArr;

  delete tempArr;
}

//Option 2 in the Main Menu
void BMScontrol::removeCourse(DList* arr)
{
  if (arr->getNumNodes() == 0){
    return;
  }
  string code;
  Course* course = 0;
  Book* book = 0;
  view->validCourse(arr,&course);
  int num = course -> getNumBooks();
  for(int i=0; i<num; i++){
    course -> getBook(i,&book);
    if(book != 0){productArr->removeProduct(book);}
  }
  //course -> getBook(0,&book);
  //std::cout << "Book: " << book->getTitle() << " Course: " << course->getName() << std::endl;

  if(book != 0){productArr->removeProduct(book);}
  (*arr)-=course;
}
