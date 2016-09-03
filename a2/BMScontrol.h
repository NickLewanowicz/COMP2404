#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "DList.h"

class BMScontrol {
  public:
    BMScontrol();
    ~BMScontrol();
    void launch();
  private:
    UImanager*   view;
    DList* courses;
		BookArray*   textbooks;
};

#endif
