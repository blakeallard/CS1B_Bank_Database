//
// Created by Blake Allard on 5/2/2025.
//

#ifndef CHECKINGS_H
#define CHECKINGS_H
#include "Account.h"


class Checkings : public Account
{
private:
    double checkingsBalance = 100.00;

public:
    Checkings();

    void Deposit(double amount)override;
    bool Withdrawal(double amount)override;
    void DisplayBalance()override;
};



#endif //CHECKINGS_H
