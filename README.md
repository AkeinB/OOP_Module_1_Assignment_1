# Module_1_Assignment_1
Group Members:
Akein Bantin,
Chevar Prince,
Jashuel Gilzene,
Ryan Brown,
Zhane Tomline 


Create a Software Application for XYZ Bank that allows its members to access their bank account 
information through an “ATM like” interface. The Menu Options should include: checking the account 
balance, debiting the account and crediting the account, along with an option to exit the program. [Hint*-
Use while loop & switch statements for menu]  

Create an Account Class to represent the customers’ bank accounts which represents the UML Diagram 
above. Provide a constructor that can receive an initial balance and uses it to initialize the data member.

The constructor should validate the initial balance to ensure that it’s greater than or equal to $1000.00. If not, set the balance to 0 and display an warning message to the user indicating that the initial balance was invalid. 

Provide three member functions:  
Member function Deposit() should add an amount to the current balance.           
Member function Withdraw()  should withdraw money from the Account and ensure that the debit 
amount does not exceed the Account’s balance. If it does, the balance should be left unchanged, and the 
function should print a message indicating "Debit amount exceeded account balance."  
Member function GetBalance() should return the account’s current balance.  
Create a console application in C++ that meet the requirements outlined above.