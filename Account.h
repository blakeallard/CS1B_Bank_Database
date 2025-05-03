//
// Created by Blake Allard on 5/2/2025.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "iostream"
#include "iomanip"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;




class Account
{
public:
    Account();

    virtual void Deposit(double amount) = 0;
    virtual bool Withdrawal(double amount) = 0;
    virtual void DisplayBalance() = 0;
};



#endif //ACCOUNT_H
