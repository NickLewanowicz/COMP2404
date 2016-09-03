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
  cout << "  ( 2 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 3 )  Add textbook" << endl;
  cout << "  ( 4 )  List course textbooks" << endl << endl;

  cout << "  ( 0 )  Exit" << endl << endl;

  while (*choice < 0 || *choice > 4) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

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
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  *course = new Course(subj, num, name, inst, enrol);

}

void UImanager::printCourses(CourseArray *arr)
{
  cout << endl << endl << "ALL COURSES:" << endl << endl;

  for (int i=0; i<arr->getSize(); ++i) {
    Course* c = arr->getCourse(i);
    cout << "Course:     " << c->getCode()  << "  " << c->getName() << endl;
    cout << "Instructor: " << c->getInstr()  << endl;
    cout << "Enrolment:  " << c->getEnrol() << endl;
    cout << "Textbooks:  ";
    if (c->getNumBooks() == 0) {
      cout << "None" << endl;
    }
    else {
      cout << endl;
    }
    cout << endl;
  }
}

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
