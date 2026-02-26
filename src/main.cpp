#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Account.h"

using namespace std;

void loadAccounts(vector<Account> &accounts) {
    ifstream file("data/accounts.txt");

    // file existence check
    if(!file) {
        cout << "No existing data file found. Starting fresh.\n";
        return;
    }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);

        int accNo, pin;
        string name;
        double balance;

        ss >> accNo >> name >> balance >> pin;

        accounts.push_back(Account(accNo, name, balance, pin));
    }

    file.close();
}

void saveAccounts(vector<Account> &accounts) {
    ofstream file("data/accounts.txt");

    for(auto &acc : accounts) {
        file << acc.getAccountNumber() << " "
            << acc.getName() << " "
            << acc.getBalance() << " "
            << acc.getPin() << "\n";
    }

    file.close();
}

int main() {
    vector<Account> accounts;

    // load accounts at the start
    loadAccounts(accounts);

    int choice;
    
    while(true) {
        cout << "\n===== Banking System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Amount\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;
        
        switch(choice) {

            case 1: {
                int accNo, pin;
                string name;
                double balance;

                cout << "Enter Account Number: ";
                cin >> accNo;

                cout << "Enter Name: ";
                cin >> name;

                cout << "Enter Initial Balance: ";
                cin >> balance;

                cout << "Set PIN: ";
                cin >> pin;

                accounts.push_back(Account(accNo, name, balance, pin));
                cout << "Account created successfully!\n";
                break;
            }

            case 2: {
                int accNo;
                double amount;

                cout << "Enter Account Number: ";
                cin >> accNo;

                bool found = false;

                for(auto &acc : accounts) {
                    if(acc.getAccountNumber() == accNo) {
                        
                        cout << "Enter amount to deposit: ";
                        cin >> amount;

                        if(acc.deposit(amount)) {
                            cout << "Deposit Successfully!\n";
                        } else {
                            cout << "Invalid deposit amount.\n";
                        }

                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Account not found!\n";
                }
                break;
            }

            case 3: {
                int accNo;
                double amount;

                cout << "Enter Account Number: ";
                cin >> accNo;

                bool found = false;

                for(auto &acc : accounts) {
                    if(acc.getAccountNumber() == accNo) {
                        
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;

                        if(acc.withdraw(amount)) {
                            cout << "Withdrawal Successfully!\n";
                        } else {
                            cout << "Insufficient Balance.\n";
                        }
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 4: {
                int accNo;
                
                cout << "Enter Account Number: ";
                cin >> accNo;

                bool found = false;

                for(auto &acc : accounts) {

                    if(acc.getAccountNumber() == accNo) {
                        cout << "Account Holder: " << acc.getName() << endl;
                        cout << "Available Balance: " << acc.getBalance() << endl;

                        found = true;
                        break;
                    }
                }

                if(!found) {
                    cout << "Account not found.\n";
                }
                break;
            }

            case 5: {
                saveAccounts(accounts);

                cout << "Data saved successfully. Exiting Program...\n";
                return 0;
            }

            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}