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

        void displayAccountInfo() {
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Current Balance: $" << balance << endl;
        }
    };

    void displayMenu(bool accountCreated) {
        if (accountCreated == false)
        {
            cout << "\n1. Create Account" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Check Balance" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
        }else
        {
            cout << "\n1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Check Balance" << endl;
            cout << "4. Exit" << endl;
        }
        
        
    }

    void deposit(BankAccount* account){
        double depositAmount;
        cout << "Enter amount to deposit: ";
        cin >> depositAmount;
        account->deposit(depositAmount);
    }

    void withdraw(BankAccount* account){
        double withdrawAmount;
        cout << "Enter amount to withdraw: ";
        cin >> withdrawAmount;
        account->withdraw(withdrawAmount);
    }

    void displayBalance(BankAccount* account){
        cout << "Current Balance: $" << account->getBalance() << endl;
    }

    int main() {
        BankAccount* account = nullptr;
        string choice;
        bool end  = false;
        bool accountCreated = false;
        
        cout << "Welcome to Simple Bank System" << endl;
        string name;
        double initialDeposit;
        

        do
        {
            displayMenu(accountCreated);
            try
            {
                cin >> choice;
                cin.ignore();
                int userChoice = std::stoi(choice);
                if (accountCreated == true)
                {
                    userChoice += 1;
                }
                
                switch (userChoice) {
                    case 1:
                        cout << "Enter account holder name: ";
                        getline(cin, name);
                        cout << "Enter initial deposit: ";
                        cin >> initialDeposit;
                        cin.ignore();
                    
                        account = new BankAccount(name, initialDeposit);
                        cout << "Account created successfully!" << endl;
                        accountCreated = true;
                        break;
                    case 2:
                        if (accountCreated == false)
                        {
                            cout << "You need an account to deposit money." << endl;
                            break;
                        }
                        deposit(account);
                        break;
                    case 3:
                        if (accountCreated == false)
                        {
                            cout << "You need an account to withdraw money." << endl;
                            break;
                        }
                        withdraw(account);
                        break;
                    case 4:
                        if (accountCreated == false)
                        {
                            cout << "You need an account to see current balance." << endl;
                            break;
                        }
                        displayBalance(account);
                        break;
                    case 5:
                        cout << "Thank you for using Simple Bank System!" << endl;
                        delete account; // delete account in memory
                        end = true;
                        return 0;
                    default:
                        cout << "Invalid choice! Please enter a number between 1-5." << endl;
                }
            }
            catch(const std::exception& e)
            {
                std::cout << "Please enter a valid number" << std::endl;
            }
            
        } while (!end);
    
    }