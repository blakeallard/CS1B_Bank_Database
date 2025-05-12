
// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: Checkings.h
// DATE: 5/2/2025
// PURPOSE: Defines the Checkings class which is derived from Account class
// INPUT: None (header file)
// OUTPUT: None (header file)
// ***************************************************************************

#ifndef CHECKINGS_H
#define CHECKINGS_H

#include "Account.h"

// ***************************************************************************
// CLASS DECLARATION
// ***************************************************************************

class Checkings : public Account
{
private:
    double checkingsBalance; // Holds the balance of the checkings account
    int    idNum;           // Stores the unique ID for the checkings account

public:
    // ***********************************************************************
    // FUNCTION: Checkings (Constructor)
    // PURPOSE : Initializes a new Checkings account
    // INPUT   : None (sets default balance to 100.00)
    // ***********************************************************************

    Checkings();

    // ***********************************************************************
    // FUNCTION: SetID
    // PURPOSE : Sets the ID for the checkings account
    // INPUT   : IDFromFile - The ID to set for the account
    // ***********************************************************************

    void SetID(int IDFromFile);

    // ***********************************************************************
    // FUNCTION: GetID
    // PURPOSE : Returns the current ID for the checkings account
    // OUTPUT  : Returns the account ID as an integer
    // ***********************************************************************

    int GetID();

    // ***********************************************************************
    // FUNCTION: PlusID
    // PURPOSE : Increments the account ID by 1
    // INPUT   : None
    // ***********************************************************************

    void PlusID();

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
    // PURPOSE : Sets the balance for the checkings account
    // INPUT   : amount - The amount to set for the balance
    // ***********************************************************************

    void SetBalance(double amount);

    // ***********************************************************************
    // FUNCTION: GetBalance
    // PURPOSE : Returns the current checkings balance
    // OUTPUT  : Returns the balance as a double
    // ***********************************************************************

    double GetBalance();

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
    // PURPOSE : Displays the current checkings balance
    // OUTPUT  : Prints balance to console
    // ***********************************************************************

    void DisplayBalance() override;
};

#endif // CHECKINGS_H