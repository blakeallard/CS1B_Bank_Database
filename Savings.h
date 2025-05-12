// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: Savings.h
// DATE: 5/2/2025
// PURPOSE: Defines the Savings class which is derived from Account class
// INPUT: None (header file)
// OUTPUT: None (header file)
// ***************************************************************************

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

// ***************************************************************************
// CLASS DECLARATION
// ***************************************************************************

class Savings : public Account
{
private:
    double savingsBalance; // Holds the balance of the savings account
    int    idNum;         // Stores the unique ID for the savings account

public:
    // ***********************************************************************
    // FUNCTION: Savings (Constructor)
    // PURPOSE : Initializes a new Savings account
    // INPUT   : startingBalance - Initial balance (default 0.0)
    // ***********************************************************************

    Savings(double startingBalance = 0.0);

    // ***********************************************************************
    // FUNCTION: SetID
    // PURPOSE : Sets the ID for the savings account from a file
    // INPUT   : IDFromFile - The ID to set for the account
    // ***********************************************************************

    void SetID(int IDFromFile);

    // ***********************************************************************
    // FUNCTION: GetID
    // PURPOSE : Returns the current ID for the savings account
    // OUTPUT  : Returns the account ID as an integer
    // ***********************************************************************

    int GetID();

    // ***********************************************************************
    // FUNCTION: SetTransCount
    // PURPOSE : Sets the transaction count for the account
    // INPUT   : transCount - Number of transactions to set
    // ***********************************************************************

    void SetTransCount(int transCount);

    // ***********************************************************************
    // FUNCTION: GetTransCount
    // PURPOSE : Returns the current transaction count
    // OUTPUT  : Returns transaction count as an integer
    // ***********************************************************************

    int GetTransCount();

    // ***********************************************************************
    // FUNCTION: PlusTransCount
    // PURPOSE : Increments the transaction count by 1
    // INPUT   : None
    // ***********************************************************************

    void PlusTransCount();

    // ***********************************************************************
    // FUNCTION: SetBalance
    // PURPOSE : Sets the balance for the savings account
    // INPUT   : amount - The amount to set for the balance
    // ***********************************************************************

    void SetBalance(double amount);

    // ***********************************************************************
    // FUNCTION: GetBalance
    // PURPOSE : Returns the current savings balance
    // OUTPUT  : Returns the balance as a double
    // ***********************************************************************

    double GetBalance() const;

    // ***********************************************************************
    // FUNCTION: Deposit
    // PURPOSE : Deposits specified amount into the account
    // INPUT   : amount - Amount to deposit
    //           silent - Whether to suppress output messages
    // ***********************************************************************

    void Deposit(double amount, bool silent) override;

    // ***********************************************************************
    // FUNCTION: Withdrawal
    // PURPOSE : Withdraws specified amount from the account
    // INPUT   : amount - Amount to withdraw
    //           silent - Whether to suppress output messages
    // OUTPUT  : Returns true if successful, false otherwise
    // ***********************************************************************

    bool Withdrawal(double amount, bool silent) override;

    // ***********************************************************************
    // FUNCTION: DisplayBalance
    // PURPOSE : Displays the current savings balance
    // OUTPUT  : Prints balance to console
    // ***********************************************************************

    void DisplayBalance() override;
};

#endif // SAVINGS_H