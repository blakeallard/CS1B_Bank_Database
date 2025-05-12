// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: Account.cpp
// DATE: 5/2/2025
// PURPOSE: Implements the Account class functions defined in Account.h
// ***************************************************************************

#include "Account.h"

// ***************************************************************************
// FUNCTION: Account (Constructor)
// PURPOSE : Initializes the transaction count to 0 for the account
// INPUT   : None (transaction count is set to 0 by default)
// ***************************************************************************

Account::Account()
{
    transCount = 0; // Initialize the transaction count to 0
}

int Account::IncrementTransCount()
{
    return transCount++;
}
