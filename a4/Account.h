#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

#include <iostream>
#include <string>


class Account
{
  public:
    Account(int,string,int);
    ~Account();
    //const string menu = ;
    bool login(string);
    virtual string logout() = 0;
    virtual string print() = 0;
    virtual string getInfo() = 0;
    int getNum();
    bool setPassword(string, string);
    //void setPerm(int i);
    int getPerm();
  private:
    string password;
    int userNum;
    int perm;
};

#endif
