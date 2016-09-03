#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

Account::Account(int num, string pass, int permission)
{
  userNum = num;
  password = pass;
  perm = permission;
}

Account::~Account()
{

}

int Account::getPerm(){return perm;}

bool Account::setPassword(string guess, string newPass)
{
  if(login(guess)){
    password = newPass;
    return true;
  }else{
    return false;
  }
}

int Account::getNum()
{
  return userNum;
}

bool Account::login(string guess)
{
  if(guess == password){
    return true;
  }else{
    return false;
  }
}
