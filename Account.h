// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: Account.h
// DATE: 5/2/2025
// PURPOSE: Abstract base class for bank accounts used to define interface for
//          derived account types (Savings, Checkings)
// INPUT: User inputs for transactions (deposit, withdrawal)
// OUTPUT: Transaction counts and balance display
// ***************************************************************************

#ifndef ACCOUNT_H
#define ACCOUNT_H

// ***************************************************************************
// HEADER FILES
// ***************************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// ***************************************************************************
// CLASS DECLARATION
// ***************************************************************************

class Account
{
public:
    int transCount; // Tracks number of transactions for possible fee logic

    // ***********************************************************************
    // FUNCTION: Account
    // PURPOSE : Default constructor for initializing transaction count
    // ***********************************************************************

    Account();

    int IncrementTransCount();

    // ***********************************************************************
    // FUNCTION: Deposit (pure virtual)
    // PURPOSE : Allows derived classes to implement deposit logic
    // INPUT   : Amount to deposit
    // ***********************************************************************

    virtual void Deposit(double amount, bool silent) = 0;

    // ***********************************************************************
    // FUNCTION: Withdrawal (pure virtual)
    // PURPOSE : Allows derived classes to implement withdrawal logic
    // INPUT   : Amount to withdraw
    // OUTPUT  : Boolean indicating success of withdrawal
    // ***********************************************************************

    virtual bool Withdrawal(double amount, bool silent) = 0;

    // ***********************************************************************
    // FUNCTION: DisplayBalance (pure virtual)
    // PURPOSE : Displays current account balance
    // ***********************************************************************

    virtual void DisplayBalance() = 0;
};

#endif // ACCOUNT_H
