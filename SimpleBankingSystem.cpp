#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class BankAccount {
    private:
        string accountHolderName;
        string accountNumber;
        double balance;
    
    public:
        // constructor to initialize
        BankAccount(string name, double initialBalance) {
            accountHolderName = name;
            accountNumber = to_string(rand() % 999999999); //random account number
            balance = initialBalance;
        }
    
        // deposit
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
                cout << "Deposit successful! New balance: $" << balance << endl;
            } else {
                cout << "ERROR! Please enter a valid amount." << endl;
            }
        }
    
        // withdraw
        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                cout << "Withdraw successful! New balance: $" << balance << endl;
            } else if (amount > balance) {
                cout << "Insufficient funds!" << endl;
            } else {
                cout << "ERROR! Please enter a valid amount." << endl;
            }
        }
    
        // get balance
        double getBalance() {
            return balance;
        }
    };

    int main() {
        BankAccount* account = nullptr;
        int choice;
    
        cout << "Welcome to Simple Bank System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
    
        
        while (choice != 1) {
            if (choice == 5) {
                cout << "Thank you for using Simple Bank System!" << endl;
                return 0;
            }
            cout << "You need to create an account first." << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
        }
    
        // create an account
        string name;
        double initialDeposit;
        cout << "Enter account holder name: ";
        getline(cin, name);
        cout << "Enter initial deposit: ";
        cin >> initialDeposit;
        cin.ignore();
    
        account = new BankAccount(name, initialDeposit);
        cout << "Account created successfully!" << endl;
    
            cout << "\n1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Exit" << endl;
            
        // loop until exit    
        while (true) { 
            
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();
    
            switch (choice) {
                case 1:
                    double depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    account->deposit(depositAmount);
                    break;
                case 2:
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    account->withdraw(withdrawAmount);
                    break;
                case 3:
                    cout << "Current Balance: $" << account->getBalance() << endl;
                    break;
                case 4:
                    cout << "Thank you for using Simple Bank System!" << endl;
                    delete account; // delete account in memory
                    return 0;
                default:
                    cout << "Invalid choice! Please enter a number between 1-4." << endl;
            }
        }
    }