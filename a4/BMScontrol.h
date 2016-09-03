#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "DList.h"
#include "ProductArray.h"
#include "Account.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
    void addCourse(DList<Course>*);
    void addCourses(DList<Course>*);
    void addAccount(DList<Account>*);
    void removeCourses(DList<Course>*);
    void removeCourse(DList<Course>*);
    void findAccount(int, Account**);
  private:
    UImanager*   view;
    DList<Course>* courses;
    DList<Account>* accounts;
		BookArray*   textbooks;
    ProductArray* productArr;
};

#endif
