#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "DList.h"
#include "ProductArray.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
    void addCourse(DList*);
    void addCourses(DList*);
    void removeCourses(DList*);
    void removeCourse(DList*);
  private:
    UImanager*   view;
    DList* courses;
		BookArray*   textbooks;
    ProductArray* productArr;
};

#endif
