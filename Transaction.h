#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
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
        ostringstream out;
        out << fixed << setprecision(2);
        out << "Transaction: " << type << " Amount: $" << amount;
        return out.str();
    }
};

#endif // TRANSACTION_H