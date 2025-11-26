#include <iostream>
using namespace std;

// =====================
// Base Class: Account
// =====================
class Account {
protected:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 1000.00) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "WARNING: Initial balance invalid. Balance set to $0.00\n";
        }
    }

    // Deposit money
    virtual void Deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount.\n";
    }

    // Withdraw money
    virtual bool Withdraw(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance.\n";
            return false;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    double GetBalance() const {
        return balance;
    }
};

// ===========================
// Derived Class: SavingsAccount
// ===========================
class SavingsAccount : public Account {
private:
    double interestRate;  // Example: 0.05 = 5%

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance) {
        interestRate = rate;
    }

    double CalculateInterest() const {
        return balance * interestRate;
    }
};

// ============================
// Derived Class: ChequingAccount
// ============================
class ChequingAccount : public Account {
private:
    double transactionFee;

public:
    ChequingAccount(double initialBalance, double fee)
        : Account(initialBalance) {
        transactionFee = fee;
    }

    // Override Withdraw to include fee
    bool Withdraw(double amount) override {
        if (Account::Withdraw(amount)) {
            balance -= transactionFee;
            cout << "Transaction fee of $" << transactionFee << " charged.\n";
            return true;
        }
        return false;
    }

    // Override Deposit to include a fee (optional but typical)
    void Deposit(double amount) override {
        Account::Deposit(amount);
        balance -= transactionFee;
        cout << "Transaction fee of $" << transactionFee << " charged.\n";
    }
};

// =======================
// MAIN PROGRAM (TESTING)
// =======================
int main() {
    cout << "===== Savings Account Test =====\n";
    SavingsAccount savings(2000.00, 0.05);  // 5% interest

    cout << "Initial Savings Balance: $" << savings.GetBalance() << endl;

    double interest = savings.CalculateInterest();
    cout << "Interest Earned: $" << interest << endl;

    savings.Deposit(interest);
    cout << "Balance After Adding Interest: $" << savings.GetBalance() << endl;


    cout << "\n===== Chequing Account Test =====\n";
    ChequingAccount chequing(1500.00, 2.00); // $2 per transaction

    cout << "Initial Chequing Balance: $" << chequing.GetBalance() << endl;

    cout << "Attempting to withdraw $300...\n";
    chequing.Withdraw(300);
    cout << "Balance After Withdrawal and Fee: $" << chequing.GetBalance() << endl;

    cout << "Depositing $200...\n";
    chequing.Deposit(200);
    cout << "Balance After Deposit and Fee: $" << chequing.GetBalance() << endl;

    return 0;
}
