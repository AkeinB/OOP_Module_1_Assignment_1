#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
using namespace std;




//====================
//Transaction Class
///====================
class Transaction
{
    private:
        double amount;
        string type;
    public:
    Transaction(double amt, string t) : amount(amt), type(t) {}
    
    string report() const
    { 
        return "Transaction: " + type +" Amount: $" + to_string(amount);
    }
};

#endif // TRANSACTION_H