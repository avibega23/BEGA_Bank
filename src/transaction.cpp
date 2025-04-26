#include "transaction.h"
#include <bits/stdc++.h>
using namespace std;

Transaction::Transaction(int transaction_id,int account_number,string type,double amount)
{
    this->transaction_id = transaction_id;
    this->account_number = account_number;
    this->type = type;
    this->amount = amount;
}

void Transaction::display()
{
    cout << "Transaction Id :-" << transaction_id << endl;
    cout << "Account Number:-" << account_number << endl;
    cout << "Type:- " << type << endl; 
    cout << "Amount:-" << amount << endl;
    cout << "TimeStamp:-" << ctime(&timestamp) << endl;
}