#ifndef CONTROL_H
#define CONTROL_H

#include "defs.h"
#include "UI.h"
#include "Animal.h"

class Control {
  public:
    Control();
    ~Control();
    void launch();
  private:
    UI*   view;
};

#endif
