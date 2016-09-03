#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "DList.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);
    void addCourse(DList*);
    void removeCourse(DList*);
    void listCourseBooks(DList*);
		void findCourse(DList*, Course**, string str);
    void getTextbookData(Book**);
    void addTextbook(DList*);
    void printCourses(DList*);
		void printCourseBooks(Course*);
		void printBooks(BookArray*);
    void pause();
  private:
    int getInt();
};

#endif
