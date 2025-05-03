//
// Created by Blake Allard on 5/2/2025.
//

#include "Checkings.h"

Checkings::Checkings()
{
    checkingsBalance = 100.00;
}

void Checkings::Deposit(double amount)
{
    if (amount == 0)
    {
        cout << "Amount must be more than 0.  Please try again.\n\n";
    }
    else
    {
        checkingsBalance += amount;
        cout << "$" << amount << " successfully deposited into your savings account.\n\n";
    }
}

bool Checkings::Withdrawal(double amount)
{
    if (amount == 0)
    {
        cout << "Amount must be more than 0.  Please try again.\n\n";
        return false;
    }
    if (amount > checkingsBalance)
    {
        cout << "Insufficient Funds! Please choose an amount equal to or less than $" << checkingsBalance << "\n\n";
        return false;
    }
    checkingsBalance -= amount;
    cout << "$" << amount << " successfully withdrawn from your savings account.\n\n";
    return true;
}

void Checkings::DisplayBalance()
{
    cout << "Checkings: $" << checkingsBalance << "\n\n";
}