#include<iostream>
#include<exception>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
using namespace std;
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"


//======================
// Main Function
//======================
int main()
{
    double initial_deposit;
    int choice;//variable to store user choice
    double amount;
    int account_type; //variable to store account type selection

    cout <<"Enter Initial Balance: $";
    cin >> initial_deposit;

    while( !cin.good() ) //input validation for initial deposit
    {
        cout << "INVALID INPUT!!. Please enter a numeric value for the initial balance: $"<< endl;
        cin.clear(); // clears the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards invalid input
        cin >> initial_deposit;
    }

    // Prompt user to select account type (savings or checking) with validation
    cout << "Select account type:\n1. Savings\n2. Checking\nEnter choice (1 or 2): ";
    cin >> account_type;
    while (!cin.good() || (account_type != 1 && account_type != 2))
    {
        cout << "\nINVALID INPUT!!. Enter 1 for Savings OR 2 for Checking: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> account_type;
    }

    // Create either a Savings Account or Checking Account based on user selection
    Account* user_account = nullptr;
    if (account_type == 1)
    {
        user_account = new SavingsAccount(initial_deposit);
        cout << "//-----Savings account created.------//" << endl;
    }
    else // account_type == 2
    {
        user_account = new CheckingAccount(initial_deposit);
        cout << "//-----Checking account created.------//" << endl;
    }

    do{
        cout << "===============================" << endl;
        cout << "\n-----XYZ Bank ATM Menu-----\n" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. View Transactions added" << endl;
        cout << "5. Save Transactions added" << endl;
        cout << "6. Exit\n" << endl;
        cout << "Select an option (1-6): ";
        cin >> choice;
        cout << "===============================" << endl;

    while( !cin.good() || choice < 1 || choice > 6 ) //input validation for menu choice
    {
        cout << "INVALID INPUT!!. Please enter a number between 1 and 6: "<< endl;
        cin.clear(); // clears the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards invalid input
        cin >> choice;
    }

        switch(choice)
        {
            case 1:
                {
                    cout << "Current Balance: $" << user_account->getBalance() << endl;
                    
                    if(dynamic_cast<SavingsAccount*>(user_account)) //check if user_account is a SavingsAccount
                    {
                        double interest = dynamic_cast<SavingsAccount*>(user_account)->calculateInterest();
                        cout << "Total Interest earned: $" << interest << endl;
                    }
                    break;
                }

            case 2:
                {
                    cout << "Enter amount to deposit: $";
                    cin >> amount;
                    user_account->deposit(amount);// Corrections made

                    if (dynamic_cast<SavingsAccount*>(user_account)) //check if user_account is a SavingsAccount
                    {
                        double interest = dynamic_cast<SavingsAccount*>(user_account)->calculateInterest();
                        cout << "Interest earned: $" << interest << endl;
                    }
                    break;
                }

            case 3:
                {
                    cout << "Enter amount to withdraw: $";
                    cin >> amount;
                    user_account->withdraw(amount);//Corrections made
                    break;
                }

            case 4:
                {
                    user_account->report(); //Shows Transaction history
                    break;
                }
            
            case 5:
                {//Saves Transaction history to file
                    user_account->saveReportToFile(); //NOTE: Program must RUN with ADMINISTRATOR PRIVILEGES to save to C:\
                    break;
                }

            case 6:
                {
                    cout << "Thank you for using XYZ Bank ATM. Goodbye!" << endl;
                    break;
                }

            default:
                {
                    cout << "Invalid option. Please select a valid option (1-4)." << endl;
                    break;
                }
        }


    } while (choice != 6); //menu loop, cancels when user selects 6.

return 0;
}