#include <iostream>
using namespace std;

struct ATM
{
    long long acNo;
    int ifsc;
    int pin;
    int bal;
    int name[25];
};

int checkPin(ATM*);
int welcome(ATM*);
 
int main(void){
    int check = 1;
    struct ATM user[2];
    user[0] = {10001, 1111, 3333, 2500};
    user[1] = {10002, 1111, 4444, 5000};
    do
    {
        cout<<"********************************************\n";
        int pin;
        cout << "Please Insert your Atm card.\n";
        cout << "ENTER YOUR SECRET PIN NUMBER: ";
        cin >> pin;
        for (int i = 0; i < 2; i++)
        {
            if (user[i].pin == pin)
            {
                welcome(&user[i]);
            }
        }
    } while (true);
}

int welcome(ATM *user){
    int quit = 1;
    do
    {
        int choice = 0;
        cout<<"********Welcome to ATM Service***************\n";
        cout<<"1. Check Balance\n2. Withdraw Cash\n3. Deposit Cash\n4. Quit\n";
        cout<<"******************?**************************\n\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            if(checkPin(user)){
            cout<<"Your Balance is: "<<user->bal<<"\n\n";}
            break;
        case 2:
            int withdraw;
            cout<<"ENTER THE AMOUNT TO WITHDRAW: "<<"\n";
            cin>>withdraw;
            if (withdraw % 100 != 0)
                {
                    cout<<"\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100";
                }
            else if (withdraw >(user->bal - 500))
                {
                    printf("\n INSUFFICENT BALANCE");
                }
            else
                {
                    if(checkPin(user)){
                    cout<<user->bal;
                    user->bal -= withdraw;
                    cout<<"\n\n PLEASE COLLECT CASH";
                    cout<<"\n YOUR CURRENT BALANCE IS "<<user->bal;}
                }
            break;
        case 3:
            int deposit;
            if(checkPin(user)){
                cout<<"\n ENTER THE AMOUNT TO DEPOSIT: ";
                cin>>deposit;
                
                user->bal += deposit;
                cout<<"YOUR BALANCE IS "<<user->bal;}
            break;
        case 4:
            cout<<"\nTHANKS FOR USING OUR ATM SERVICE\n\n\n\n"; 
            quit = 0;
            break;
        default:
            cout<<"INVALID CHOICE";
        }
    } while (quit);
    return 1;
}

int checkPin(ATM *user){
    int pin;
    for (int i = 0; i < 3; i++)
    {
        cout << "ENTER YOUR SECRET PIN NUMBER: ";
        cin >> pin;
        if (user->pin == pin )
        {
            return 1;
        }
        cout << "Invalid pin.\nPlease Enter again:\n";
    }
    
    
    return 0;
}