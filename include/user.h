#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
using namespace std;

class User{
    private:
        string name;
        int account_number;
        double balance;
    public:
        User(string name,int ac,double balance=0);
        void deposit(double ammout);
        bool withdraw(double amount);
        void showDetails();      

};
#endif