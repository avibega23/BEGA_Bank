#include "bank.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    Bank bank;
    bank.loadFromFile("bankdata.txt");
    
    int choice;
    do{
        cout << "1. Create Account" << endl << "2. Login" << endl << "3. View Transactions" << endl << "4. Exit" << endl << "Enter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            bank.createAccount();
        }
        else if(choice == 2)
        {
            int ac;
            cout << "Enter Account Number: ";
            cin >> ac;
            User* user = bank.login(ac);
            if(user)
            {
                cout << "Login Succesful" << endl;
                int action;
                do{
                    cout << "1. Deposit" << endl << "2. Withdraw" << endl<<"3. Check Details" << endl << "Log out" << endl << "Enter Choice: ";
                    cin >> action;

                    if(action == 1)
                    {
                        double amount;
                        cout << "Enter Amount To Deposit: ";
                        cin >> amount;
                        bank.deposit(user,amount);
                    }
                    else if(action == 2)
                    {
                        double amount;
                        cout << "Enter Amount To Withdraw: ";
                        cin >> amount;
                        bank.withdraw(user,amount);
                    }
                    else if(action == 3)
                    {
                        user->showDetails();
                    }
                    else
                    {
                        break;
                    }
                }
                while(true);
            }
            else
            {
                cout << "Account Not Found" << endl;
            }
        }
        else if(choice == 3)
        {
            bank.displayTransactions();
        }
        else if(choice == 4)
        {
            bank.saveToFile("bankdata.txt");
            cout << "Exiting, Thank You!" << endl;
        }
        else
        {
            cout << "Invalid Choice,Try Again" << endl; 
        }
    }
    while(choice != 4);

    return 0;
}