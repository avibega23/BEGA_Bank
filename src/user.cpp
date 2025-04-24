#include "user.h"
#include <bits/stdc++.h>
using namespace std;

User::User(string name,int ac,double balance)
{
    this->name = name;
    this->account_number = ac;
    this->balance = balance;
}

void User::deposit(double amount)
{
    balance += amount;
}

bool User::withdraw(double amount)
{
    if(amount>balance) return false;
    balance -= amount;
    return true;
}

void User::showDetails()
{
    cout << "Name: " << name << endl;
    cout << "Account No: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}