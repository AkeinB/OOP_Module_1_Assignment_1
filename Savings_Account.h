#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>
#include "Account.h"
using namespace std;

//================================
// Derived class: Savings Account
//=================================
class SavingsAccount : public Account //class derived from base class Account
{
    private:
        double interestRate; 
    public:
        SavingsAccount(double init_balance) : Account(init_balance) //constructor inherited from base class Account
        {
            interestRate = 0.05; //assign interest rate of 5% to interestRate variable
        }
    
        double calculateInterest() //function to calculate interest earned
        {
            return Balance * interestRate;
        }
};
#endif // SAVINGS_ACCOUNT_H