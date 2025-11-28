#include <iostream>
#include <string>
#include <limits>
using namespace std;

/// ====================
// Base class: Account
// =====================
class Account
{
    protected:// chnaged from private to protected to allow access in derived classes
        double Balance;
    
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
                cout << "Initial balance must be a $1000 or greater. Setting balance to $0.0" << endl;
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
            return Balance;
        }

        virtual bool withdraw(double amount)//function to withdraw money from account // change from bool to virtual bool
        {
            if (amount <= Balance)
            {
                Balance -= amount;
                cout << "----Withdrawal processed----" << endl;
                return true;
            }
            else 
            {
                cout << "Debit amount exceeded account balance."  << endl;
                return false;
            }
        }
};

//================================
// Derived class: Savings Account
//=================================
class SavingsAccount : public Account //class derived from base class Account
{
    private:
        double interestRate; 
    public:
        SavingsAccount(double init_balance, double rate = 0.05) : Account(init_balance) //constructor inherited from base class Account
        {
            interestRate = rate; //assign interest rate of 5% to interestRate variable
        }
    
        double calculateInterest() //function to calculate interest earned
        {
            return Balance * interestRate;
        }
};
//================================
// Derived class: Checking Account
//=================================
class CheckingAccount : public Account //class derived from base class Account
{
    private:
        double transactionfee;
    public:
        CheckingAccount(double init_balance, double fee = 2.00) : Account(init_balance) //constructor inherited from base class Account
        {
            transactionfee = fee; //innitial transaction fee
        }

        bool withdraw(double amount) override//override withdraw function to include transaction fee
        {
            double totalAmount = amount + transactionfee; //total amount to withdraw including transaction fee
            if (totalAmount <= Balance)
            {
                Balance -= totalAmount;
                cout << "----Withdrawal processed with transaction fee of $" << transactionfee << "----" << endl;
                return true;
            }
            else 
            {
                cout << "Debit amount plus transaction fee exceeded account balance."  << endl;
                return false;
            }
        }

        double deposit(double amount) override//override deposit function to include transaction fee
        {
            Balance += amount;
            Balance -= transactionfee; //deduct transaction fee from deposit
            cout << "-----Deposit processed with transaction fee of $" << transactionfee << "----." << endl;
            return true;
        }
};


int main()
{
    double initial_deposit;
    int choice;//variable to store user choice
    double amount;
    int account_type; //variable to store account type selection

    cout <<"Enter Initial Balance: $"<< endl;
    cin >> initial_deposit;

    while( !cin.good() ) //input validation for initial deposit
    {
        cout << "Invalid input. Please enter a numeric value for the initial balance: $"<< endl;
        cin.clear(); // clears the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards invalid input
        cin >> initial_deposit;
    }

    // Prompt user to select account type (savings or checking) with validation
    cout << "Select account type:\n1. Savings\n2. Checking\nEnter choice (1 or 2): " << endl;
    cin >> account_type;
    while (!cin.good() || (account_type != 1 && account_type != 2))
    {
        cout << "Invalid input. Enter 1 for Savings or 2 for Checking: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> account_type;
    }

    // Create either a Savings Account or Checking Account based on user selection
    Account* user_account = nullptr;
    if (account_type == 1)
    {
        user_account = new SavingsAccount(initial_deposit);
        cout << "Savings account created." << endl;
    }
    else // account_type == 2
    {
        user_account = new CheckingAccount(initial_deposit);
        cout << "Checking account created." << endl;
    }

    do{
        cout << "\n-----XYZ Bank ATM Menu-----\n" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit\n" << endl;
        cout << "Select an option (1-4): "<< endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                {
                    cout << "Current Balance: $" << user_account->getBalance() << endl;
                    break;
                }

            case 2:
                {
                    cout << "Enter amount to deposit: $";
                    cin >> amount;
                    user_account->deposit(amount);// Corrections made
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
                    cout << "Thank you for using XYZ Bank ATM. Goodbye!" << endl;
                    break;
                }

            default:
                {
                    cout << "Invalid option. Please select a valid option (1-4)." << endl;
                    break;
                }
        }


    } while (choice != 4); //menu loop, cancels when user selects 4.


return 0;
}