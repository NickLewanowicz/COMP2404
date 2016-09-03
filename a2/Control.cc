#include <iostream>
#include "Control.h"

using namespace std;

Control::Control()
{
  view = new UImanager();
}

Control::~Control(){
  delete  view;
}

void Control::launch()
{

  while (1) {
    int numAnimals = 0;
    string name = "";
    view->start(&numAnimals);
    view->pause();
  }
}
