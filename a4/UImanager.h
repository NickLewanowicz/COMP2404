#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "DList.h"
#include "Account.h"
#include "ProductArray.h"
#include "Pen.h"
#include "Calculator.h"
#include "Comp.h"
#include "Admin.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"


#define TEST_MODE

class UImanager {
  public:
    void mainMenu(Account*, int*);
    void subMenu(int*);
    //void accMenu(Account*,int*);
    int loginUser();
    string loginPass();
    void getCourseData(Course**);
    void getAccountData(Account**);
    void arrayInput(string*);
    void validCourse(DList<Course>*,Course**);
    void listCourseBooks(DList<Course>*);
		void findCourse(DList<Course>*, Course**, string str);
    void getTextbookData(Book**);
    void addTextbook(DList<Course>*, Course**);
    void addPen(ProductArray*, Product**);
    void addCalculator(ProductArray*, Product**);
    void addComp(ProductArray*, Product**);
    void addBook(ProductArray*, Product**);
    void printCourses(DList<Course>*);
		void printCourseBooks(Course*);
		void printBooks(BookArray*);
    void test(DList<Course>*);
    void pause();
  private:
    int getInt();
    float getFloat();
    bool getBool();
    double getDouble();
};

#endif
