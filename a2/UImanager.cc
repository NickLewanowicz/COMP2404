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

  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 5) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}
//Option 1 in the Main Menu
void UImanager::addCourse(DList* arr)
{
  Course* course;
  getCourseData(&course);
  arr->add(course);
}

//Option 2 in the Main Menu
void UImanager::removeCourse(DList* arr)
{
  if (arr->getNumNodes() == 0){
    cout << "No courses in list to remove. Please add a course to list." << endl;
    return;
  }
  string code;
  Course* course = 0;
  while ((code.length() != 8) || (course == 0)) {
    cout << "Please enter the code of the course you want to remove:" << endl;
    getline(cin, code);
    findCourse(arr, &course, code);
  }
  arr->removeCourse(course);
}

//Option 4 in the Main Menu
void UImanager::addTextbook(DList* arr)
{
  if (arr->getNumNodes() == 0){
    cout << "No courses in list. Please add a course to list." << endl;
    return;
  }
  string code;
  Book* book;
  Course* course;
  while ((code.length() != 8) || (course == 0)) {
    cout << "Enter course code the textbook belongs to:  ";
    getline(cin, code);
    course = arr->getCourse(code);
    //findCourse(arr, &course, code);
  }
  cout << endl;
  getTextbookData(&book);
  course->addBook(book);
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
    for(int i = 0; i < numNodes; i++){
      if(arr->getCourse(i)->getCode() == str){
        *course = arr->getCourse(i);
        return;
      }
      course = 0;
    }
}

//Helper function to collect info and make a book
void UImanager::getTextbookData(Book** book){
	string str="", str2="";
	string title, author, isbn;
	int edition, year;

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

	*book = new Book(title, author, isbn, edition, year);
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
