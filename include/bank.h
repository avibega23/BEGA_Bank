#ifndef BANK_H
#define BANK_H

#include "user.h"
#include<bits/stdc++.h>
using namespace std;
class Bank{
    private:
        vector<User>users;
    public:
        void createAccount(string name,float first_deposit);
        
};

#endif