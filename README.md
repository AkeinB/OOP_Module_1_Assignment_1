# Module_1_Assignment_2
Group Members:
Akein Bantin,
Chevar Prince,
Jashuel Gilzene,
Ryan Brown,
Zhane Tomline 


Building on the project from Assignment 1, we will add features for specific types of accounts that exist in a real Bank. Savings accounts, for instance, earn interest on the money they hold.
Chequing accounts, on the other hand, charge a fee per transaction (i.e., credit or debit).

Create an Inheritance hierarchy using base class Account and derived classes Savings- Account and CheckingAccount.

Derived class SavingsAccount should inheritted  the functionality of an Account, but also include a data member indicating the interest rate (percentage) assigned to the Account.
SavingsAccount’s constructor should inherit from the Account constructor, as well as have a parameter for the SavingsAccount’s interest rate.

SavingsAccount should provide a public member function CalculateInterest() that returns a double indicating the amount of interest earned by an account. 
Member function CalculateInterest should determine this amount by multiplying the interest rate by the account balance. [Note: SavingsAccount should inherit member functions credit and debit as is without redefining them.]

Derived class ChequingAccount should inherit from base class Account and include an additional data member that represents the fee charged per transaction.
ChequingAccount’s constructor should also inherit from the Account class constructor, as well as a parameter indicating a fee amount.

Class ChequingAccount should redefine member function debit/withdraw so that it will
subtract the fee from the account balance whenever the transaction is performed successfully. The function should charge a fee only if money is actually withdrawn (i.e., the debit amount does not exceed the account balance).

After defining the classes in this hierarchy, write a program that creates objects of each class
and tests their member functions. For e.g. Add interest to the SavingsAccount object by first invoking its calculateInterest function, then adding the returned interest amount to the Savings object’s balance, and make a withdrawal from the ChequingAccount object and see if the fee was also subtracted.
function. 
