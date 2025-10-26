#include <iostream>
#include <string>
using namespace std;


class Account
{
    private:
        double Balance;
    
    public:
        Account(double balance)
        {
            Balance = 0.0;
        }
        void setBalance();
        double getBalance();
        double deposit();
        bool withdraw();
};
int main()
{

    cout << "-----Welcome XYZ Bank-----" << endl;


return 0;
}