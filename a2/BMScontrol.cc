#include <iostream>
#include "BMScontrol.h"

using namespace std;

BMScontrol::BMScontrol()
{
  view = new UImanager();
  courses = new DList();
  textbooks = new BookArray();
}

BMScontrol::~BMScontrol(){
  delete  view;
  delete  courses;
	delete  textbooks;
}

void BMScontrol::launch()
{
  int    choice;
  string code;
  Course* course;

  while (1) {
    choice = -1;
    course = 0;
    code = "";
    view->mainMenu(&choice);
    if (choice == 0) {
      break;
    }
    else if (choice == 1) {
      view->addCourse(courses);
    }
    else if (choice == 2) {
      view->removeCourse(courses);
    }
    else if (choice == 3) {
      cout << courses->forward() << endl;
      cout << courses->backward() << endl;
    }
    else if (choice == 4) {
      view->addTextbook(courses);
    }
    else if (choice == 5) {
      view->listCourseBooks(courses);
    }
    view->pause();
  }
}
