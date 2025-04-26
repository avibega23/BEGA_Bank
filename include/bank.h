#ifndef BANK_H
#define BANK_H
#include "transaction.h"
#include "user.h"
#include <bits/stdc++.h>
using namespace std;

class Bank{
    private:
        vector<Transaction>transactions;
        int transation_counter = 0;
        vector<User>users;

    public:
        void createAccount();
        User* login(int account_number);
        void saveToFile(const string &filename);
        void loadFromFile(const string &filename);

        //Transaction management system

        void deposit(User* user,double ammount);
        bool withdraw(User* user,double amount);
        void displayTransactions();
};     

#endif