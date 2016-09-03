#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "DList.h"
#include "ProductArray.h"
#include "Pen.h"
#include "Calculator.h"
#include "Comp.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void subMenu(int*);
    void getCourseData(Course**);
    void arrayInput(string*);
    void validCourse(DList*,Course**);
    void listCourseBooks(DList*);
		void findCourse(DList*, Course**, string str);
    void getTextbookData(Book**);
    void addTextbook(DList*, Course**);
    void addPen(ProductArray*, Product**);
    void addCalculator(ProductArray*, Product**);
    void addComp(ProductArray*, Product**);
    void addBook(ProductArray*, Product**);
    void printCourses(DList*);
		void printCourseBooks(Course*);
		void printBooks(BookArray*);
    void test(DList*);
    void pause();
  private:
    int getInt();
    float getFloat();
    bool getBool();
};

#endif
