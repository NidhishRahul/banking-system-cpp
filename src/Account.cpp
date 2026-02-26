#include "Account.h"
#include <iostream>

Account::Account(int accNo, string accName, double initialBalance, int accPin) {
    accountNumber = accNo;
    name = accName;
    balance = initialBalance;
    pin = accPin;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getPin() const {
    return pin;
}

double Account::getBalance() const {
    return balance;
}

string Account::getName() const {
    return name;
}

bool Account::deposit(double amount) {
    if(amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if(amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}