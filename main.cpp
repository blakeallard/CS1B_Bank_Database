#include "Savings.h"
#include "Checkings.h"

void BankMenu();
void MainMenu();
bool Login();
bool Signup();


int main()
{
    Savings   savings;
    Checkings checkings;
    int       choice{};
    int       secondChoice{};
    double    depositAmt{};
    double    withdrawalAmt{};

    do
    {
        MainMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
            {
                if (Login() == true)
                {
                    do
                    {
                        BankMenu();
                        cin >> secondChoice;
                        cin.ignore();

                        switch (secondChoice)
                        {
                            case 1:
                            {
                                cout << "Enter amount to deposit in your savings account: ";
                                cin  >> depositAmt;
                                cin.ignore();
                                savings.Deposit(depositAmt);
                                break;
                            }
                            case 2:
                            {
                                cout << "Enter amount to deposit in your checkings account: ";
                                cin  >> depositAmt;
                                cin.ignore();
                                checkings.Deposit(depositAmt);
                                break;
                            }
                            case 3:
                            {
                                cout << "Enter amount to withdrawal in your savings account: ";
                                cin  >> withdrawalAmt;
                                cin.ignore();
                                savings.Withdrawal(withdrawalAmt);
                                break;
                            }
                            case 4:
                            {
                                cout << "Enter amount to withdrawal in your checkings account: ";
                                cin  >> withdrawalAmt;
                                cin.ignore();
                                checkings.Withdrawal(withdrawalAmt);
                                break;
                            }
                            case 5:
                            {
                                savings.DisplayBalance();
                                checkings.DisplayBalance();
                                break;
                            }
                            case 6:
                            {
                                cout << "Exiting Bank Menu...\n\n";
                                break;
                            }
                            default:
                            {
                                cout << "ERROR! Please enter a valid option (1-6)\n\n";
                            }
                        } // end secondChoice Switch Statement
                    } while (secondChoice != 6);
                } // end if (Login() == true)
                break; // break from Bank Menu
            } // end case 1 of Bank Menu
            case 2:
            {
                Signup();
                break;
            }
            case 3:
            {
                cout << "Exiting Program...\n\n";
                break;
            }
            default: cout << "ERROR! Please enter a valid choice!\n\n";
        }
    } while (choice != 3);


    return 0;
}

void MainMenu()
{
    cout << "******* MAIN MENU *******\n";
    cout << "1. Login\n";
    cout << "2. Signup\n";
    cout << "3. Quit Program\n\n";
    cout << "Enter your choice: ";
}

void BankMenu()
{
    cout << "******* MAIN MENU *******\n";
    cout << "1. Savings Deposit\n";
    cout << "2. Checkings Deposit\n";
    cout << "3. Savings Withdrawal\n";
    cout << "4. Checkings Withdrawal\n";
    cout << "5. Display Account Balances\n";
    cout << "6. Exit\n\n";
    cout << "Enter your choice: ";
}

bool Login()
{
    // VARIABLES - declare local variables
    string fileUsername{};
    string filePassword{};
    string inputUsername{};
    string inputPassword;
    string line{};

    // open file and assign it to "fin" variable
    ifstream fin("Passwords.txt");

    // INPUT -
    cout << "Username :";
    getline(cin, inputUsername);
    cout << "Password: ";
    getline(cin, inputPassword);

    // ERROR CHECK - check if file opened, if not return false
    if (!fin)
    {
        cout << "ERROR! UNABLE TO OPEN FILE\n\n";
        return false;
    }

    // PROCESSING - read in file information while "fin"
    while (getline(fin, line))
    {
        stringstream ss(line);
        ss >> fileUsername >> filePassword;

        if (inputUsername == fileUsername && inputPassword == filePassword)
        {
            cout << "Login Successful.\n\n";
            return true;
        }
    }
    // FORMATTING - close file
    fin.close();
    cout << "Username or password does not exist!  Please signup.\n\n";
    return false;
}

bool Signup()
{
    string   newUsername{};
    string   newPassword{};
    ofstream fout("Passwords.txt", ios:: app);

    cout << "Choose a username: ";
    getline(cin, newUsername);

    cout << "Choose a password: ";
    getline(cin, newPassword);

    if (!fout)
    {
        cout << "Error opening file.\n\n";
        return false;
    }

    fout << newUsername << " " << newPassword << endl;
    fout.close();
    cout << "Signup successfull!\n\n";

    return true;
}