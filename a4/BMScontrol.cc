#include <iostream>
#include "BMScontrol.h"
#include "DList.h"

using namespace std;

BMScontrol::BMScontrol()
{
  view = new UImanager();
  courses = new DList<Course>();
  accounts = new DList<Account>();
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
  Account* loggedIn = 0;
  Course* course;
  Book* book;
  Product* product;

  while (1) {
    choice = -1;
    course = 0;
    book = 0;
    product = 0;
    int perm = 0;

    view->mainMenu(loggedIn,&choice);
    if(loggedIn != 0){
    perm = loggedIn->getPerm();
      switch(perm){
        case 1:
          if(choice != 3 && choice != 5 && choice != 7 && choice != 8 && choice != 0){
            choice = -2;
          }
          break;
        case 2:
          if(choice == 1 || choice == 2 || choice == 3){
            choice = -2;
          }
          break;
        case 3:
          if(choice == 6 || choice == 7 || choice == 9 || choice == 10){
            choice = -2;
          }
      }
    }
    if (choice == 0) {
      break;
    }
    else if (choice == -2){
      cout << "You do not have appropriate permission." << endl << "Please login as a higher permission user." << endl;
    }
    else if (choice == 1) {
        view->subMenu(&choice);
    }
    else if (choice == 2) {
        view->subMenu(&choice);
    }
    else if (choice == 3) {
      //cout << courses->forward() << endl;
      //cout << courses->backward() << endl;
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
    else if (choice == 8) {//Login to account
      if (loggedIn == 0){
        if(accounts->getNumNodes() > 0)
        {
          int num;
          loggedIn = 0;
          string guess;
          while(1){
            num = view->loginUser();
            findAccount(num, &loggedIn);
            if(loggedIn != 0){break;}
          }
          guess = view->loginPass();
          if (!(loggedIn->login(guess)))
          {
            loggedIn = 0;
            cout << "Failed Log in." << endl;
          }else{
            cout << "Successfully Logged in." << endl;
          }
        }
      }else{
        loggedIn = 0;
        cout << "Successfully Logged out." << endl;
      }
    }
    else if (choice == 9) {//Register an account
      addAccount(accounts);
    }
    else if (choice == 10) { //Print all users
      int size = accounts->getNumNodes();
      for(int i = 0;i<size;i++){
        cout << "(" << i+1 << ") " << accounts->getCourse(i)->getInfo() << endl << endl;
      }
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

void BMScontrol::addCourse(DList<Course>* arr)
{
  Course* course;
  view->getCourseData(&course);
  //arr->add(course);
  (*arr) += course;
}

void BMScontrol::addCourses(DList<Course>* arr)
{
  DList<Course>* tempArr = new DList<Course>();
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

void BMScontrol::removeCourses(DList<Course>* arr)
{
  DList<Course>* tempArr = new DList<Course>();
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
void BMScontrol::removeCourse(DList<Course>* arr)
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

void BMScontrol::findAccount(int num, Account** found)
{
  //cout << "Test";
  int size = accounts->getNumNodes();
  if (size == 0){return;}
  Account* temp;
  //cout<< size;
  for(int i = 0; i<size; i++){
    //cout << "Looking " << i;
    temp = accounts->find(i);
    //cout << temp->getNum() << " " << num << endl;
    if(temp->getNum() == num){
      *found = temp;
    }
  }
}

void BMScontrol::addAccount(DList<Account>* arr)
{
  Account* acc;
  view->getAccountData(&acc);
  //arr->add(course);
  (*arr) += acc;
}
