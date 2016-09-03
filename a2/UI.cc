#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UI.h"

using namespace std;

void UImanager::start(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BARNYARD BASH 2!!!!" << endl<<endl;
  cout << "  How many birds?" << endl;

  while (*choice < 0 || *choice > 5) {
    cout << "Enter your selection:  ";
    *choice = getInt();
  }
}

int UImanager::getInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}
