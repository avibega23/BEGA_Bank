#include "transaction.h"
#include "user.h"
#include "bank.h"

#include<bits/stdc++.h>
using namespace std;

void Bank::createAccount()
{
    string name;
    int accountNumber;
    double balance;

    cout << "Name:- ";
    cin >> name;
    cout << name << endl;
    cout << "Enter Account Number:- ";
    cin >> accountNumber;
    cout << accountNumber << endl;
    cout << "Enter Initital Balance:- " << endl;
    cin >> balance;

    users.push_back(User(name,accountNumber,balance));

    cout << "Account Created Succesfully" << endl;
}

User* Bank::login(int account_number)
{
    for(auto &user:users)
    {
        if(user.account_number == account_number)
        {
            return &user;
        }
    }
    return nullptr;
}

void Bank::saveToFile(const string &filename)
{
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file for saving!" << endl;
        return;
    }

    for (auto& user : users) {
        file << user.name << " " << user.account_number << " " << user.balance << endl;
    }

    for (auto& transaction : transactions) {
        file << transaction.transaction_id << " "
             << transaction.account_number << " "
             << transaction.amount << " "
             << transaction.type << " "
             << ctime(&transaction.timestamp); // Saving transaction details
    }

    file.close();
    cout << "Data saved to file successfully!" << endl;
}

void Bank::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "No data file found, starting fresh." << endl;
        return;
    }

    string name;
    int account_number;
    double balance;

    while (file >> name >> account_number >> balance) {
        users.push_back(User(name, account_number, balance));
    }

    int transaction_id;
    string type;
    double amount;
    time_t timestamp;

    while (file >> transaction_id >> account_number >> amount >> type >> timestamp) {
        transactions.push_back(Transaction(transaction_id, account_number, type, amount));
    }

    file.close();
    cout << "Data loaded from file successfully!" << endl;
}

void Bank::deposit(User* user,double amount)
{
    user->deposit(amount);

    transactions.push_back(Transaction(transation_counter++,user->account_number,"deposit",amount));
    cout << "Deposit Succesfully" << endl;
}

bool Bank::withdraw(User* user,double amount)
{
    if(user->withdraw(amount))
    {
        transactions.push_back(Transaction(transation_counter++,user->account_number,"withdraw",amount));
    }
    else
    {
        cout << "Insufficent Funds" << endl;
        return false;
    }
    return true;
}

void Bank::displayTransactions()
{
    if(transactions.empty())
    {
        cout<< "No Transactions Found";
        return;
    }
    cout << "All Transactions : ";
    for(auto trans:transactions)
    {
        trans.display();
    }

}
