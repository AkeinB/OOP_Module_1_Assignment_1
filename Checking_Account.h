#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <iostream>
using namespace std;
#include "Account.h"


//================================
// Derived class: Checking Account
//=================================
class CheckingAccount : public Account //class derived from base class Account
{
    private:
        double transactionfee;
    public:
        CheckingAccount(double init_balance) : Account(init_balance) //constructor inherited from base class Account
        {
            transactionfee = 2.00; //innitial transaction fee
        }

        bool withdraw(double amount) override//override withdraw function to include transaction fee
        {
            double totalAmount = amount + transactionfee; //total amount to withdraw including transaction fee
            if (totalAmount <= Balance)
            {
                Balance -= totalAmount;
                cout << "----Withdrawal processed with transaction fee of $" << transactionfee << "----" << endl;
                addTransaction(Transaction(amount, "Withdrawal (with fee)")); //Recorded with the fee
                return true;
            }
            else 
            {
                cout << "----Debit amount plus transaction fee exceeded account balance.-----"  << endl;
                return false;
            }
        }

        double deposit(double amount) override//override deposit function to include transaction fee
        {
            Balance += amount;
            Balance -= transactionfee; //deduct transaction fee from deposit
            cout << "-----Deposit processed with transaction fee of $" << transactionfee << "----." << endl;
            addTransaction(Transaction(amount, "Deposit (with fee)")); //Recorded with the fee
            return true;
        }
};

#endif // CHECKING_ACCOUNT_H