// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: Checkings.cpp
// DATE: 5/2/2025
// PURPOSE: Implements the Checkings class functions defined in Checkings.h
// ***************************************************************************

#include "Checkings.h"

// ***************************************************************************
// FUNCTION: Checkings (Constructor)
// PURPOSE : Initializes the checkings balance to a default value of 100.00
// INPUT   : None (default balance set to 100.00)
// ***************************************************************************

Checkings::Checkings()
{
    checkingsBalance = 100.00; // Set default checkings balance to 100.00
}

// ***************************************************************************
// FUNCTION: SetID
// PURPOSE : Sets the account ID from the data file
// INPUT   : IDFromFile - integer value read from the file
// ***************************************************************************

void Checkings::SetID(int IDFromFile)
{
    this->idNum = IDFromFile; // Set account ID using the provided value
}

// ***************************************************************************
// FUNCTION: GetID
// PURPOSE : Returns the current account ID
// OUTPUT  : Returns the account ID as an integer
// ***************************************************************************

int Checkings::GetID()
{
    return idNum; // Return the current account ID
}

// ***************************************************************************
// FUNCTION: PlusID
// PURPOSE : Increments the account ID by 1
// INPUT   : None
// ***************************************************************************

void Checkings::PlusID()
{
    idNum++; // Increment the account ID by 1
}

// ***************************************************************************
// FUNCTION: SetTransCount
// PURPOSE : Sets the transaction count for the account
// INPUT   : transCount - integer value representing transaction count
// ***************************************************************************

void Checkings::SetTransCount(int transCount)
{
    this->transCount = transCount; // Set transaction count to the provided value
}

// ***************************************************************************
// FUNCTION: GetTransCount
// PURPOSE : Returns the current transaction count
// OUTPUT  : Returns the transaction count as an integer
// ***************************************************************************

int Checkings::GetTransCount()
{
    return transCount; // Return the current transaction count
}

// ***************************************************************************
// FUNCTION: PlusTransCount
// PURPOSE : Increments the transaction count by 1
// INPUT   : None
// ***************************************************************************

void Checkings::PlusTransCount()
{
    transCount++; // Increment the transaction count by 1
}

// ***************************************************************************
// FUNCTION: SetBalance
// PURPOSE : Sets the checkings balance to a new value
// INPUT   : amount - double value representing the new balance
// ***************************************************************************

void Checkings::SetBalance(double amount)
{
    checkingsBalance = amount; // Set the checkings balance to the provided value
}

// ***************************************************************************
// FUNCTION: GetBalance
// PURPOSE : Returns the current checkings balance
// OUTPUT  : Returns the checkings balance as a double
// ***************************************************************************

double Checkings::GetBalance()
{
    return checkingsBalance; // Return the current checkings balance
}

// ***************************************************************************
// FUNCTION: Deposit
// PURPOSE : Deposits the specified amount into the checkings account
// INPUT   : amount - double value to deposit
// OUTPUT  : Prints a confirmation message to the console
// ***************************************************************************

void Checkings::Deposit(double amount, bool silent)
{
    if (amount == 0)                  // Check if the deposit amount is zero
    {
        if (!silent)
        {
            cout << "Amount must be more than 0.  Please try again.\n\n"; // Prompt for valid deposit amount
        }
    }
    else
    {
        if (transCount >= 5)          // Check if there have been 5 or more transactions
        {
            checkingsBalance -= 0.10; // Apply a 10 cent transaction fee
            if (!silent)
            {
                cout << "A transaction fee of 10 cents has been applied.\n\n";
                transCount++; // Update transaction count if deposit or withdrawal
            }
        }
        checkingsBalance += amount;   // Add the deposit amount to the checkings balance
        if (!silent)
        {
            cout << "$" << amount << " successfully deposited into your checkings account.\n\n";
            transCount++; // Update transaction count if deposit or withdrawal
        }
    }
}

// ***************************************************************************
// FUNCTION: Withdrawal
// PURPOSE : Withdraws the specified amount from the checkings account
// INPUT   : amount - double value to withdraw
// OUTPUT  : bool - true if withdrawal is successful, false otherwise
// ***************************************************************************

bool Checkings::Withdrawal(double amount, bool silent)
{
    if (amount == 0)  // Check if the withdrawal amount is zero
    {
        if (!silent)
        {
            cout << "Amount must be more than 0.  Please try again.\n\n"; // Prompt for valid withdrawal amount
        }
        return false;
    }
    if (amount > checkingsBalance)          // Check if there are sufficient funds
    {
        if (!silent)
        {
            cout << "Insufficient Funds! Please choose an amount equal to or less than $"
                 << checkingsBalance << "\n\n"; // Display insufficient funds message
        }
        return false;
    }
    if (transCount >= 5) // Check if there have been 5 or more transactions
    {
        amount += 0.10;  // Apply a 10 cent transaction fee to the withdrawal amount
        if (!silent)
        {
            cout << "A transaction fee of 10 cents has been applied.\n\n";
            transCount++; // Update transaction count if deposit or withdrawal
        }
    }
    checkingsBalance -= amount; // Subtract the withdrawal amount from the checkings balance
    if (!silent)
    {
        cout << "$" << amount << " successfully withdrawn from your checkings account.\n\n";
        transCount++; // Update transaction count if deposit or withdrawal
    }
    return true;                // Return true indicating the withdrawal was successful
}

// ***************************************************************************
// FUNCTION: DisplayBalance
// PURPOSE : Displays the current checkings balance
// OUTPUT  : Prints the current checkings balance to the console
// ***************************************************************************

void Checkings::DisplayBalance()
{
    cout << "Checkings: $" << checkingsBalance << "\n\n"; // Display the current checkings balance
}
