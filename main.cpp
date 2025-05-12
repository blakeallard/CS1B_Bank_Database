// ***************************************************************************
// AUTHOR: Blake Allard
// FILENAME: main.cpp
// DATE: 5/2/2025
// PURPOSE: Bank Account Management System that handles user accounts,
//          transactions, and balance management for savings and checkings
// INPUT: User commands for account management and transactions
// OUTPUT: Account information, balances, and transaction results
// ***************************************************************************

#include "Savings.h"
#include "Checkings.h"

/******************************************************************************
 * FUNCTION PROTOTYPES
 * ----------------------------------------------------------------------------
 * Declares functions for menu control, authentication, balance saving/loading,
 * and transferring funds between accounts.
 *****************************************************************************/

void BankMenu();
void MainMenu();
bool Login(string &username);
bool Signup(Checkings &checkings);
bool LoadBalances(const string &username, Savings &savings, Checkings &checkings);
bool SaveBalances(const string &username, Savings &savings, Checkings &checkings);
string GetUsernameFromID(int id);
bool FindUserID(int &idNum);
bool TransferFunds(Savings &senderSavings, Checkings &senderCheckings, string &username);

/******************************************************************************
 * FUNCTION: main
 * ----------------------------------------------------------------------------
 * This is the entry point of the program. It presents a main menu that lets
 * the user login or sign up, and from there, access their account to manage
 * balances, perform transactions, and save their data.
 *
 * INPUT   : Console input for user choices and credentials.
 * OUTPUT  : Console output showing prompts, account info, and confirmation.
 *****************************************************************************/

int main()
{
  // Declaring objects
    Savings   savings{};           //***************************************************
                                   // PROCESSING - Object for managing savings account
                                   //***************************************************
    Checkings checkings{};         //***************************************************
                                   // PROCESSING - Object for managing checkings account
                                   //***************************************************
    // Declaring variables
    int       choice{};            //***************************************************
                                   // IN - Prompts user for menu choice
                                   //***************************************************
    int       secondChoice{};      //***************************************************
                                   // IN - Prompts user for secondary menu option
                                   //***************************************************
    double    depositAmt{};        //***************************************************
                                   // IN - Amount to deposit into selected account
                                   //***************************************************
    double    withdrawalAmt{};     //***************************************************
                                   // IN - Amount to withdraw from selected account
                                   //***************************************************
    string    username{};          //***************************************************
                                   // IN/OUT - Username used for login and file reference
                                   //***************************************************
    string    recipientUsername{}; //***************************************************
                                   // IN - Username of the transfer recipient
                                   //***************************************************
    int       idNum{};             //***************************************************
                                   // IN - User ID number for identification
                                   //***************************************************
    bool      toSavings;           //***************************************************
                                   // IN - Determines if transfer is to savings (true) or checkings (false)
                                   //***************************************************
    double    amount;              //***************************************************
                                   // IN - General-purpose amount (used for transfers)
                                   //***************************************************


    do
    {
        // Display the main menu
        MainMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1: // Login
            {
                if (Login(username))
                {
                    if (!LoadBalances(username, savings, checkings))
                    {
                        cout << "No saved balances found.\n\n";
                    }
                    do
                    {
                        // Display the bank menu
                        BankMenu();
                        cin >> secondChoice;
                        cin.ignore();

                        switch (secondChoice)
                        {
                            case 1: // Savings Deposit
                            {
                                do
                                {
                                    cout << "Enter amount to deposit in your savings account: ";
                                    cin >> depositAmt;
                                    cin.ignore();
                                    if (depositAmt < 0)
                                    {
                                        cout << "ERROR! Please enter an amount greater than 0\n\n";
                                    }
                                } while (depositAmt < 0);

                                checkings.PlusTransCount();
                                savings.Deposit(depositAmt, false);
                                SaveBalances(username, savings, checkings);
                                break;
                            } // end case 1

                            case 2: // Checkings Deposit
                            {
                                do
                                {
                                    cout << "Enter amount to deposit in your checkings account: ";
                                    cin >> depositAmt;
                                    cin.ignore();
                                    if (depositAmt < 0)
                                    {
                                        cout << "ERROR! Please enter an amount greater than 0\n\n";
                                    }
                                } while (depositAmt < 0);

                                checkings.PlusTransCount();
                                checkings.Deposit(depositAmt, false);
                                SaveBalances(username, savings, checkings);
                                break;
                            } // end case 2


                            case 3: // Savings Withdrawal
                            {
                                do // ERROR CHECK - if withdrawalAmt < 0, do not update transCount & reprompt
                                {
                                    cout << "Enter amount to withdraw from your savings account: ";
                                    cin >> withdrawalAmt;
                                    cin.ignore();
                                    if (withdrawalAmt < 0)
                                    {
                                        cout << "ERROR! Please enter an amount greater than 0\n\n";
                                    }
                                } while (withdrawalAmt < 0);

                                checkings.PlusTransCount();
                                savings.Withdrawal(withdrawalAmt, false);
                                SaveBalances(username, savings, checkings);
                                break;
                            } // end case 3


                            case 4: // Checkings Withdrawal
                            {
                                do
                                {
                                    cout << "Enter amount to withdraw from your checkings account: ";
                                    cin >> withdrawalAmt;
                                    cin.ignore();
                                    if (withdrawalAmt < 0)
                                    {
                                        cout << "ERROR! Please enter an amount greater than 0\n\n";
                                    }
                                } while (withdrawalAmt < 0);

                                checkings.PlusTransCount();
                                checkings.Withdrawal(withdrawalAmt, false);
                                SaveBalances(username, savings, checkings);
                                break;
                            } // end case 4

                            case 5: // Display Account Balances
                            {
                                savings.DisplayBalance();
                                checkings.DisplayBalance();
                                break;
                            }

                            case 6: // Transfer Funds
                            {

                                FindUserID(idNum);
                                TransferFunds(savings, checkings, username);
                                checkings.PlusTransCount();
                                break;
                            }

                            case 7: // Exit
                            {
                                cout << "Exiting Bank Menu...\n\n";
                                break;
                            }

                            default:
                                cout << "ERROR! Please enter a valid option (1-7)\n\n";

                        } // end secondChoice switch statement

                    } while (secondChoice != 7);

                } // end if (Login() == true)

                break;

            } // end case 1 Login()

            case 2: // Signup
                Signup(checkings);
                break;

            case 3: // Find ID# (Not implemented)
                break;

            case 4: // Quit Program
                cout << "Exiting Program...\n\n";
                break;

            default:
                cout << "ERROR! Please enter a valid choice!\n\n";

        } // end choice switch

    } while (choice != 4);

    return 0;
} // end of main()

// ***************************************************************************
// FUNCTION: MainMenu
// PURPOSE : Displays the main menu options
// OUTPUT  : Prints login, signup menu options to console
// ***************************************************************************

void MainMenu()
{
    cout << "******* MAIN MENU *******\n";
    cout << "1. Login\n";
    cout << "2. Signup\n";
    cout << "3. Find ID#\n";
    cout << "4. Quit Program\n\n";
    cout << "Enter your choice: ";
} // end of MainMenu()

// ***************************************************************************
// FUNCTION: BankMenu
// PURPOSE : Displays the banking operation menu options
// OUTPUT  : Prints menu options to console
// ***************************************************************************

void BankMenu()
{
    cout << "******* BANK MENU *******\n";
    cout << "1. Savings Deposit\n";
    cout << "2. Checkings Deposit\n";
    cout << "3. Savings Withdrawal\n";
    cout << "4. Checkings Withdrawal\n";
    cout << "5. Display Account Balances\n";
    cout << "6. Transfer Funds To User Via ID#\n";
    cout << "7. Exit\n\n";
    cout << "Enter your choice: ";
} // end of BankMenu()

// ***************************************************************************
// FUNCTION: Login
// PURPOSE : Authenticates user credentials against stored data
// INPUT   : username - Reference to store the authenticated username
// OUTPUT  : Returns true if login successful, false otherwise
// ***************************************************************************

bool Login(string &username)
{
    string fileUsername;
    string filePassword;
    string inputUsername;
    string inputPassword;
    string line;

    // Open the file containing stored usernames and passwords
    ifstream fin("Passwords.txt");

    cout << "Username: ";
    getline(cin, inputUsername);
    cout << "Password: ";
    getline(cin, inputPassword);

    if (!fin)
    {
        cout << "ERROR! UNABLE TO OPEN FILE\n\n";
        return false;
    }

    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> fileUsername >> filePassword;

        if (inputUsername == fileUsername && inputPassword == filePassword)
        {
            username = inputUsername;
            cout << "Login Successful.\n\n";
            return true;
        }
    }
    fin.close();
    cout << "Username or password does not exist! Please signup.\n\n";
    return false;
} // end of Login()

// ***************************************************************************
// FUNCTION: Signup
// PURPOSE : Registers new user account with password validation
// INPUT   : checkings - Reference to Checkings object (unused)
// OUTPUT  : Returns true if signup successful, false otherwise
// ***************************************************************************

bool Signup(Checkings &checkings)
{
    string username;
    string password;
    string confirmPassword;
    string fileUsername;
    string line;

    // Open the file containing stored usernames and passwords
    ifstream fin("Passwords.txt");

    cout << "Enter a new username: ";
    getline(cin, username);

    // Check if the username already exists
    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> fileUsername;
        if (fileUsername == username)
        {
            cout << "ERROR! Username already exists. Please try again.\n\n";
            fin.close();
            return false;
        }
    }

    fin.close();

    // Prompt user for password and confirm it
    cout << "Enter a new password: ";
    getline(cin, password);

    cout << "Confirm your password: ";
    getline(cin, confirmPassword);

    if (password != confirmPassword)
    {
        cout << "ERROR! Passwords do not match. Please try again.\n\n";
        return false;
    }

    // Open the file for appending and store the new username and password
    ofstream fout("Passwords.txt", ios::app);
    if (!fout)
    {
        cout << "ERROR! Unable to open file for writing.\n\n";
        return false;
    }

    fout << username << " " << password << endl;
    fout.close();

    cout << "Signup successful. You can now login.\n\n";
    return true;
} // end of Signup()

// ***************************************************************************
// FUNCTION: LoadBalances
// PURPOSE : Loads account balances from file for given username
// INPUT   : username - User whose balances to load
//           savings - Reference to Savings account
//           checkings - Reference to Checkings account
// OUTPUT  : Returns true if balances loaded successfully, false otherwise
// ***************************************************************************

bool LoadBalances(const string& username, Savings& savings, Checkings& checkings)
{
    ifstream fin("Balances.txt");
    if (!fin)
    {
        return false;
    }

    string line;
    string fileUser;
    double savBal, checkBal;
    int transNum;

    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> fileUser >> savBal >> checkBal >> transNum;

        if (fileUser == username)
        {
            savings.SetBalance(savBal);
            checkings.SetBalance(checkBal);
            savings.SetTransCount(transNum);
            checkings.SetTransCount(transNum);
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

// ***************************************************************************
// FUNCTION: SaveBalances
// PURPOSE : Saves account balances to file for given username
// INPUT   : username - User whose balances to save
//           savings - Reference to Savings account
//           checkings - Reference to Checkings account
// OUTPUT  : Returns true if balances saved successfully, false otherwise
// ***************************************************************************

bool SaveBalances(const string& username, Savings& savings, Checkings& checkings)
{
    ifstream fin("Balances.txt");
    ofstream fout("Balances_temp.txt");

    if (!fin || !fout)
    {
        return false;
    }

    string line;
    string fileUser;
    double savBal, checkBal;
    int    transNum;
    bool   found = false;

    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> fileUser >> savBal >> checkBal >> transNum;

        if (fileUser == username)
        {
            fout << username << " " << savings.GetBalance() << " "
                 << checkings.GetBalance() << " "
                 << max(savings.GetTransCount(), checkings.GetTransCount()) << endl;
            found = true;
        }
        else
        {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    if (!found)
    {
        return false;
    }

    remove("Balances.txt");
    rename("Balances_temp.txt", "Balances.txt");
    return true;
}

// ***************************************************************************
// FUNCTION: FindUserID
// PURPOSE : Searches for a user by their ID number
// INPUT   : idNum - Reference to store the found user ID
// OUTPUT  : Returns true if ID found, false otherwise
// ***************************************************************************

bool FindUserID(int &idNum)
{
    ifstream fin("Passwords.txt");
    string   name{};
    string   password{};
    int      fileIdNum{};
    string   line{};

    if (!fin)
    {
        cout << "ERROR! Failed to open ID records.\n\n";
        return false;
    }



    // while reading input from the file
    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> name >> password >> fileIdNum;

        // check if file id matches user input id
        if (fileIdNum == idNum)
        {
            fin.close();
            return true;
        }
    }

    cout << "ID# " << idNum << " was not found.\nPlease enter a valid ID# to transfer funds to\n\n";
    fin.close();
    return false;
}

// ***************************************************************************
// FUNCTION: GetUsernameFromID
// PURPOSE : Retrieves username associated with given ID
// INPUT   : id - User ID to look up
// OUTPUT  : Returns username if found, empty string otherwise
// ***************************************************************************

string GetUsernameFromID(int id)
{
    ifstream fin("Passwords.txt");

    string   username, password;
    int      fileID;
    string   line;

    if (!fin)
    {
        return "";
    }

    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> username >> password >> fileID;

        if (fileID == id)
        {
            fin.close();
            return username;
        }
    }
    fin.close();
    return "";
}

// ***************************************************************************
// FUNCTION: TransferFunds
// PURPOSE : Handles fund transfer between user accounts
// INPUT   : senderSavings - Reference to sender's Savings account
//           senderCheckings - Reference to sender's Checkings account
//           username - Sender's username
// OUTPUT  : Returns true if transfer successful, false otherwise
// ***************************************************************************

bool TransferFunds(Savings &senderSavings, Checkings &senderCheckings, string &username)
{
    // Get recipient's ID number
    int recipientID;
    cout << "Enter ID# to transfer funds to: ";
    cin >> recipientID;
    cin.ignore();

    // Get recipient's username and verify
    string recipientUsername = GetUsernameFromID(recipientID);
    if (recipientUsername.empty())
    {
        cout << "Transfer canceled - Invalid recipient ID.\n\n";
        return false;
    }

    // Choose user account
    int sourceChoice;
    cout << "\nTransfer from:\n"
         << "1. Savings Account (Current balance: $" << senderSavings.GetBalance() << ")\n"
         << "2. Checking Account (Current balance: $" << senderCheckings.GetBalance() << ")\n"
         << "Enter choice (1-2): ";
    cin >> sourceChoice;
    cin.ignore();

    if (sourceChoice != 1 && sourceChoice != 2)
    {
        cout << "Invalid source account selection. Transfer canceled.\n\n";
        return false;
    }

    // Choose recipient account
    int destChoice;
    cout << "\nTransfer to recipient's:\n"
         << "1. Savings Account\n"
         << "2. Checking Account\n"
         << "Enter choice (1-2): ";
    cin >> destChoice;
    cin.ignore();

    if (destChoice != 1 && destChoice != 2)
    {
        cout << "Invalid destination account selection. Transfer canceled.\n\n";
        return false;
    }

    // Get transfer amount
    double transferAmount;
    cout << "Enter amount to transfer: $";
    cin >> transferAmount;
    cin.ignore();

    if (transferAmount <= 0)
    {
        cout << "Invalid amount. Transfer must be greater than $0.\n\n";
        return false;
    }

    // Process withdrawal from sender's account
    bool withdrawalSuccess;
    if (sourceChoice == 1)
    {
        withdrawalSuccess = senderSavings.Withdrawal(transferAmount, true);
    }
    else
    {
        withdrawalSuccess = senderCheckings.Withdrawal(transferAmount, true);
    }

    if (!withdrawalSuccess)
    {
        return false;
    }

    // After successful withdrawal, immediately save sender's balances
    if (!SaveBalances(username, senderSavings, senderCheckings))
    {
        cout << "Error saving sender's balances. Canceling transfer.\n\n";
        // Reverse the withdrawal since we couldn't save it
        if (sourceChoice == 1)
        {
            senderSavings.Deposit(transferAmount, true);
        }
        else
        {
            senderCheckings.Deposit(transferAmount, true);
        }
        return false;
    }
    // Load recipient's balances
    Savings recipientSavings;
    Checkings recipientCheckings;

    if (!LoadBalances(recipientUsername, recipientSavings, recipientCheckings))
    {
        cout << "Error loading recipient's balances. Canceling transfer.\n\n";
        // Reverse the withdrawal since we couldn't complete the transfer
        if (sourceChoice == 1)
        {
            senderSavings.Deposit(transferAmount, true);
        }
        else
        {
            senderCheckings.Deposit(transferAmount, true);
        }
        SaveBalances(username, senderSavings, senderCheckings); // Save the reversal
        return false;
    }

    // Update recipient's account
    if (destChoice == 1)
    {
        recipientSavings.Deposit(transferAmount, true);
    }
    else
    {
        recipientCheckings.Deposit(transferAmount, true);
    }

    // Save recipient's updated balances
    if (!SaveBalances(recipientUsername, recipientSavings, recipientCheckings))
    {
        cout << "Error saving recipient's balances. Canceling transfer.\n\n";
        // Reverse everything since we couldn't save recipient's balance
        if (sourceChoice == 1)
        {
            senderSavings.Deposit(transferAmount, true);
        }
        else
        {
            senderCheckings.Deposit(transferAmount, true);
        }
        SaveBalances(username, senderSavings, senderCheckings); // Save the reversal
        return false;
    }

    cout << "Transfer successful! $" << transferAmount << " has been transferred to user ID "
         << recipientID << ".\n\n";
    return true;
}