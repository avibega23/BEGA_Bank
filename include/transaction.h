#ifndef TRANSACTION_H
#define TRANSACTION_H
    #include<bits/stdc++.h>
    using namespace std;

    class Transaction{
        public:
            int transaction_id;
            int account_number;
            string type;
            double amount;
            time_t timestamp;

            Transaction(int transaction_id,int account_number,string type,double amount);
            void display();
    };

#endif
