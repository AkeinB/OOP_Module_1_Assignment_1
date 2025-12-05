#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Transaction.h"
using namespace std;

/// ====================
// Base class: Account
// =====================
class Account
{
    protected:// changed from private to protected to allow access in derived classes
        double Balance;
        vector <Transaction> log; //Logs the transaction
    
    public:
        Account(double init_balance) //allows inital balance to be set when account is created and check that it is greater than $1000
        {
            if (init_balance >= 1000.00)
            {
                Balance = init_balance;
            }   
            else
            {
                Balance = 0.0;
                cout << "----Initial balance must be a $1000 or greater. Setting balance to $0.0----" << endl;
            }
            
        }

        double getBalance()//function to return current balance
        {
            return Balance;
        }

        virtual double deposit(double amount)//function to deposit money into account // change from doube to virtual double
        {
            Balance += amount;
            cout << "-----Deposit processed----." << endl;
            addTransaction(Transaction(amount, "Deposit")); //Records the Deposit
            return Balance;
        }

        virtual bool withdraw(double amount)//function to withdraw money from account // change from bool to virtual bool
        {
            if (amount <= Balance)
            {
                Balance -= amount;
                cout << "----Withdrawal processed----" << endl;
                addTransaction(Transaction(amount, "Withdrawal")); //Records the vWithdrawal
                return true;
            }
            else 
            {
                cout << "----Debit amount exceeded account balance.----"  << endl;
                return false;
            }
        }

            //function to add transaction to log
        void addTransaction(const Transaction& t)
            {
                log.push_back(t);
            }

            void report()
            {
                cout << "\n--- Transaction Report ---\n";
                for (const auto& t : log) {
                    cout << t.report() << endl;
                }
            }
        
            void saveReportToFile()//function to save transaction report to file
             {
                try {
                    ofstream file("C:\\transactions.txt");
                    if (!file) throw runtime_error("File could not be opened.");
                    file << fixed << setprecision(2);//set decimal precision to 2 e.g $100.00

                    for (const auto& t : log) {
                        file << t.report() << endl;
                    }
                    file.close();
                    cout << "Transactions saved to C:\\transactions.txt successfully." << endl;
                } catch (const exception& e) {
                    cout << "Error saving file: " << e.what() << endl;
                }
            }
};


#endif // ACCOUNT_H