#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "CourseArray.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);
    void printCourses(CourseArray*);
    void pause();
  private:
    int getInt();
};

#endif
