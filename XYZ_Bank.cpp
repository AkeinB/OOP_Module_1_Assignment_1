#include <iostream>
#include <string>
using namespace std;


class Account
{
    private:
        double Balance;
    
    public:
        Account(double init_balance) //allows inital balance to be set when account is created and check that it is greater than $1000
        {
            if (init_balance >= 1000.0)
            {
                Balance = init_balance;
            }   
            else
            {
                Balance = 0.0;
                cout << "Initial balance must be greater than $1000. Setting balance to $0.0" << endl;
            }
            
        }
        double getBalance();
        double deposit();
        bool withdraw();
};
int main()
{
    double initial_deposit;
    int choice;//variable to store user choice
    double amount;

    cout <<"Enter Initial Balance: $"<< endl;
    cin >> initial_deposit;

    Account user_account(initial_deposit);//create account object

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
                    cout << "Current Balance: $" << user_account.getBalance() << endl;
                    break;
                }

            case 2:
                {
                    cout << "Enter amount to deposit: $"<< endl;
                    cin >> amount;
                    user_account.deposit(amount);
                    break;
                }

            case 3:
                {
                    cout << "Enter amount to withdraw: $"<< endl;
                    cin >> amount;
                    user_account.withdraw(amount);
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


    } while (choice != 4);//menu loop, cancels when user selects 4


return 0;
}