#include <iostream>
#include <string>
using namespace std;

#include "CourseArray.h"

CourseArray::CourseArray()
{
  size = 0;
  courses = new Course*[1];

}

CourseArray::~CourseArray(){
  for(int i = 0;i<size;i++){
    delete courses[i];
  }
  delete[] courses;

}

int    CourseArray::getSize()        { return size; }
Course* CourseArray::getCourse(int i) { return courses[i]; }

void CourseArray::add(Course* course)
{
  ++size;

  Course** tempList = new Course*[size];
  for (int i = 0; i<size - 1; ++i){
    tempList[i] = courses[i];
  }

  delete[] courses;
  courses = tempList;
  cout << course <<endl;
  courses[size - 1] = course;
}
