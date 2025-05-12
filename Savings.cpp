
// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: Savings.cpp
// DATE: 5/2/2025
// PURPOSE: Implements the Savings class functions defined in Savings.h
// ***************************************************************************

#include "Savings.h"

// ***************************************************************************
// FUNCTION: Savings (Constructor)
// PURPOSE : Initializes a new savings account with optional starting balance
// INPUT   : startingBalance - Initial balance (default 0.0)
// ***************************************************************************

Savings::Savings(double startingBalance)
{
    savingsBalance = startingBalance;  // Initialize balance with provided value
    idNum = 0;                        // Initialize ID to 0 by default
    transCount = 0;                   // Initialize transaction count to 0
}

// ***************************************************************************
// FUNCTION: SetID
// PURPOSE : Sets the ID for the savings account
// INPUT   : IDFromFile - ID value from file
// ***************************************************************************

void Savings::SetID(int IDFromFile)
{
    idNum = IDFromFile;  // Set the ID for the savings account
}

// ***************************************************************************
// FUNCTION: GetID
// PURPOSE : Retrieves the current account ID
// OUTPUT  : Returns the account ID as an integer
// ***************************************************************************

int Savings::GetID()
{
    return idNum;  // Return the current ID
}

// ***************************************************************************
// FUNCTION: SetTransCount
// PURPOSE : Sets the transaction count for the account
// INPUT   : transCount - Number of transactions to set
// ***************************************************************************

void Savings::SetTransCount(int transCount)
{
    this->transCount = transCount;  // Set the transaction count
}

// ***************************************************************************
// FUNCTION: GetTransCount
// PURPOSE : Retrieves the current transaction count
// OUTPUT  : Returns the transaction count as an integer
// ***************************************************************************

int Savings::GetTransCount()
{
    return transCount;  // Return the current transaction count
}

// ***************************************************************************
// FUNCTION: PlusTransCount
// PURPOSE : Increments the transaction count by one
// ***************************************************************************

void Savings::PlusTransCount()
{
    transCount++;  // Increment the transaction count
}

// ***************************************************************************
// FUNCTION: SetBalance
// PURPOSE : Sets the savings account balance
// INPUT   : newBalance - New balance value to set
// ***************************************************************************

void Savings::SetBalance(double newBalance)
{
    savingsBalance = newBalance;  // Set the savings balance
}

// ***************************************************************************
// FUNCTION: GetBalance
// PURPOSE : Retrieves the current savings balance
// OUTPUT  : Returns the balance as a double
// ***************************************************************************

double Savings::GetBalance() const
{
    return savingsBalance;  // Return the current balance
}

// ***************************************************************************
// FUNCTION: Deposit
// PURPOSE : Deposits amount into savings account
// INPUT   : amount - Amount to deposit
//           silent - Whether to suppress output messages
// ***************************************************************************

void Savings::Deposit(double amount, bool silent)
{
    if (amount > 0)
    {
        savingsBalance += amount;  // Add amount to balance
        if (!silent)
        {
            transCount++;  // Increment transaction count for non-silent operations
            cout << "$" << amount << " successfully deposited into your savings account.\n\n";
        }
    }
    else
    {
        cout << "ERROR! Please enter a number greater than 0\n\n";
    }
}

// ***************************************************************************
// FUNCTION: Withdrawal
// PURPOSE : Withdraws amount from savings account
// INPUT   : amount - Amount to withdraw
//           silent - Whether to suppress output messages
// OUTPUT  : Returns true if withdrawal successful, false otherwise
// ***************************************************************************

bool Savings::Withdrawal(double amount, bool silent)
{
    if (amount > 0 && savingsBalance >= amount)
    {
        savingsBalance -= amount;  // Subtract amount from balance
        if (!silent)
        {
            transCount++;  // Increment transaction count for non-silent operations
            cout << "$" << amount << " successfully withdrawn from your savings account.\n\n";
        }
        return true;  // Withdrawal successful
    }
    return false;  // Withdrawal failed
}

// ***************************************************************************
// FUNCTION: DisplayBalance
// PURPOSE : Displays current savings balance
// OUTPUT  : Prints balance to console
// ***************************************************************************

void Savings::DisplayBalance()
{
    cout << "Savings Balance: $" << savingsBalance << endl;  // Display balance
}