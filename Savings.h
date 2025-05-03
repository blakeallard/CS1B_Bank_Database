//
// Created by Blake Allard on 5/2/2025.
//

#ifndef SAVINGS_H
#define SAVINGS_H
#include "Account.h"


class Savings : public Account
{
private:
    double savingsBalance;

public:
    Savings();

    void Deposit(double amount)override;
    bool Withdrawal(double amount)override;
    void DisplayBalance()override;
};



#endif //SAVINGS_H
