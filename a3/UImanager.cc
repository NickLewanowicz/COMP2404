#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  Remove course" << endl;
  cout << "  ( 3 )  List all courses" << endl << endl;

  cout << "  Textbook Management:" << endl;
  cout << "  ( 4 )  Add textbook" << endl;
  cout << "  ( 5 )  List course textbooks" << endl << endl;

  cout << "  Store Management:" << endl;
  cout << "  ( 6 )  Add product" << endl;
  cout << "  ( 7 )  Print Products" << endl << endl;



  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 7) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

void UImanager::subMenu(int* choice){
  if (*choice == 1){
    cout << "  ( 1 )  Add 1 course" << endl;
    cout << "  ( 2 )  Add multiple courses" << endl;
    while (*choice < 11 || *choice > 12) {
      cout << "Enter your selection:  ";
      *choice = getInt() + 10;
    }
  }
  else if (*choice == 2){
    cout << "  ( 1 )  Remove 1 course" << endl;
    cout << "  ( 2 )  Remove multiple courses" << endl;
    while (*choice < 21 || *choice > 22) {
      cout << "Enter your selection:  ";
      *choice = getInt() + 20;
    }
  }
  else if (*choice == 6){
    cout << "  ( 1 )  Add a Pen" << endl;
    cout << "  ( 2 )  Add a Calculator" << endl;
    cout << "  ( 3 )  Add a Computer" << endl;
    cout << "  ( 4 )  Add a Book" << endl;
    while (*choice < 61 || *choice > 64) {
      cout << "Enter your selection:  ";
      *choice = getInt() + 60;
    }
  }

}
//Option 1 in the Main Menu
// void UImanager::addCourse(DList* arr)
// {
//   Course* course;
//   getCourseData(&course);
//   //arr->add(course);
//   (*arr) += course;
// }
//
// void UImanager::addCourses(DList* arr)
// {
//   DList* tempArr = new DList();
//   Course* course;
//   string stop;
//   while(1){
//     getCourseData(&course);
//     (*tempArr) += course;
//     cout << endl << "Would you like to enter another course?" << endl << "y/n: ";
//     getline(cin, stop);
//     if(stop == "n"){break;}
//   }
//   (*arr)+=tempArr;
// }

// void UImanager::removeCourses(DList* arr)
// {
//   DList* tempArr = new DList();
//   Course* course;
//   string stop;
//   while(1){
//     getCourseData(&course);
//     (*tempArr) += course;
//     cout << endl << "Would you like to remove another course?" << endl << "(Y)1/(N)0: ";
//     getline(cin, stop);
//     if(stop == "0"){break;}
//   }
//   (*arr)-=tempArr;
// }
//
// //Option 2 in the Main Menu
// void UImanager::removeCourse(DList* arr)
// {
//   if (arr->getNumNodes() == 0){
//     cout << "No courses in list to remove. Please add a course to list." << endl;
//     return;
//   }
//   string code;
//   Course* course = 0;
//   while ((code.length() != 8) || (course == 0)) {
//     cout << "Please enter the code of the course you want to remove:" << endl;
//     getline(cin, code);
//     findCourse(arr, &course, code);
//   }
//   (*arr)-=course;
// }

void UImanager::arrayInput(string* str)
{
  string temp;
  cout << endl << "Would you like to specify another course?" << endl << "y/n: ";
  getline(cin, temp);
  *str = temp;
}

void UImanager::validCourse(DList* arr,Course** vCourse)
{
  string code;
  while ((code.length() != 8) || (vCourse == 0)) {
    cout << "Please enter the code of the course you want to remove:" << endl;
    getline(cin, code);
    *vCourse = arr->getCourse(code);
  }
}

//Option 4 in the Main Menu
void UImanager::addTextbook(DList* arr, Course** course)
{
  if (arr->getNumNodes() == 0){
    cout << "No courses in list. Please add a course to list." << endl;
    return;
  }
  string code;
  while ((code.length() != 8) || (course == 0)) {
    cout << "Enter course code the textbook belongs to:  ";
    getline(cin, code);
    *course = arr->getCourse(code);
    //findCourse(arr, &course, code);
  }
  cout << endl;
}

//Option to add a Pen
void UImanager::addPen(ProductArray* pArray, Product** product)
{
  string c;
  cout << "Enter color of the pen:  ";
  getline(cin, c);
  cout << "Enter the durability of the pen:  ";
  int d = getInt();
  cout << "Enter the price of the pen:  ";
  float p = getFloat();
  cout << "Enter the rating of the pen:  ";
  int r = getInt();

  *product = new Pen(c,d,p,r);
}

//Option to add a Calculator
void UImanager::addCalculator(ProductArray* pArray, Product** product)
{
  cout << "Is this a scientific Calculator (y/n):";
  bool s = getBool();
  cout << "Is this a exam approved Calculator (y/n):";
  bool e = getBool();
  cout << "What is the price of this Calculator:";
  float p = getFloat();
  cout << "Enter the rating of this Calculator:";
  int r = getInt();
  *product = new Calculator(s,e,p,r);
}
//Option to add a Comp
void UImanager::addComp(ProductArray* pArray, Product** product)
{
  string os, form;
  cout << "What is the OS of this computer?: ";
  getline(cin, os);
  cout << "What is the form factor of this computer?:";
  getline(cin, form);
  cout << "What is the price of this Computer:";
  float p = getFloat();
  cout << "Enter the rating of this Computer:";
  int r = getInt();
  *product = new Comp(os,form,p,r);
}

//Option to add a Book
void UImanager::addBook(ProductArray* pArray, Product** product)
{
  string str="", str2="";
  string title, author, isbn;
  int edition, year, s;
  float p;
  cout << endl << "Enter textbook title (e.g. Introduction to SE):  ";
  getline(cin, title);

  cout << endl << "Enter author name:  ";
  getline(cin, author);

  cout << endl << "Enter ISBN code:  ";
  getline(cin, isbn);

  cout << endl << "Enter textbook edition:  ";
  edition = getInt();

  cout << endl << "Enter textbook year:  ";
  year = getInt();

  cout << endl << "Enter textbook price:  ";
  p = getFloat();

  cout << endl << "Enter textbook rating:  ";
  s = getInt();

  *product = new Book(title, author, isbn, edition, year, p, s);
}
//Option 5 in the Main Menu
void UImanager::listCourseBooks(DList* arr)
{
  if (arr->getNumNodes() == 0){
    cout << "No courses in list. Please add a course to list." << endl;
    return;
  }
  string code;
  Course* course = 0;
  while ((code.length() != 8) || (course == 0)) {
    cout << "Enter course code you would like to view the textbooks for:  ";
    getline(cin, code);
    findCourse(arr, &course, code);
  }
  printCourseBooks(course);
}

//Helper funtion to get course data and make a course
void UImanager::getCourseData(Course** course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  enrol = getInt();

  *course = new Course(subj, num, name, inst, enrol);
}

//Helper function to find a course based on course code
void UImanager::findCourse(DList* arr, Course** course, string str){
  int numNodes = arr->getNumNodes();
  cout<<"Ok1"<<endl;
    for(int i = 0; i < numNodes; i++){
      cout<<"Ok2" << endl;
      if(arr->getCourse(i)->getCode() == str){
        cout<<"Ok3"<<endl;
        *course = arr->getCourse(i);
        cout<<"Ok4"<<endl;
        return;
      }
      course = 0;
    }
}

//Helper function to collect info and make a book
void UImanager::getTextbookData(Book** book){
	string str="", str2="";
	string title, author, isbn;
	int edition, year, s;
  float p;
	cout << endl << "Enter textbook title (e.g. Introduction to SE):  ";
	getline(cin, title);

	cout << endl << "Enter author name:  ";
	getline(cin, author);

	cout << endl << "Enter ISBN code:  ";
	getline(cin, isbn);

	cout << endl << "Enter textbook edition:  ";
	edition = getInt();

	cout << endl << "Enter textbook year:  ";
	year = getInt();

  cout << endl << "Enter textbook price:  ";
	p = getFloat();

  cout << endl << "Enter textbook rating:  ";
	s = getInt();


	*book = new Book(title, author, isbn, edition, year, p, s);
}

//Helper function to loop through the books for a course and print them
void UImanager::printCourseBooks(Course* course){
      if(course->getNumBooks() != 0){
	cout << course->printBooks() << endl;
      }else{
        cout << "None."<< endl;
      }
}

//Old print function
void UImanager::printCourses(DList* arr)
{
  cout << endl << endl << "ALL COURSES:" << endl << endl;

  for (int i=0; i<arr->getNumNodes(); ++i) {
    Course* c = arr->getCourse(i);
    cout << "Course:     " << c->getCode()  << "  " << c->getName() << endl;
    cout << "Instructor: " << c->getInstr()  << endl;
    cout << "Enrolment:  " << c->getEnrol() << endl;
    cout << "Textbooks:  ";
    if (c->getNumBooks() == 0) {
      cout << "None" << endl;
    }
    else {
      printCourseBooks(c);
    }
    cout << endl;
  }
}

//Pouse function
void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

float UImanager::getFloat()
{
  string str;
  float    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

bool UImanager::getBool()
{
  string str;
  bool   response = true;

  getline(cin, str);
  if (str == "n"){response = false;}

  return response;
}

void UImanager::test(DList* arr){
  DList* testArr = new DList();
  (*testArr) += arr->getCourse(0);
  (*testArr) += arr->getCourse(1);
  (*arr)+=testArr;
}
