//
// Created by Blake Allard on 5/2/2025.
//

#include "Savings.h"

Savings::Savings()
{
    savingsBalance = 100.00;
}

void Savings::Deposit(double amount)
{
    if (amount == 0)
    {
        cout << "Amount must be more than 0.  Please try again.\n\n";
    }
    else
    {
        savingsBalance += amount;
        cout << "$" << amount << " successfully deposited into your savings account.\n\n";
    }
}

bool Savings::Withdrawal(double amount)
{
    if (amount == 0)
    {
        cout << "Amount must be more than 0.  Please try again.\n\n";
        return false;
    }
    if (amount > savingsBalance)
    {
        cout << "Insufficient Funds! Please choose an amount equal to or less than $" << savingsBalance << "\n\n";
        return false;
    }
    savingsBalance -= amount;
    cout << "$" << amount << " successfully withdrawn from your savings account.\n\n";
    return true;
}

void Savings::DisplayBalance()
{
    cout << "Savings: $" << savingsBalance << "\n\n";
}