#include<iostream>
using namespace std;
class bank_account
{
    
    char acc_holder_name[10];
    long balance;
    long acc_num;


public:

    void add_acc_details()
    {
        cout << "Enter the account holder's name: ";
        cin >> acc_holder_name;
        cout << "Enter the account number: ";
        cin >> acc_num;

        balance = 1000;

        cout << "Account addition successful!" << endl;
    }

    inline int get_acc_num()
    {
        return acc_num;
    }

    void deposit_money()
    {
       
        long Amount;

        cout << "Enter the amount to be deposited: ";
        cin >> Amount;

        balance += Amount;

        cout << "Deposit successful!" << endl;
    }

    void withdraw_money()
    {
        
        long Amount;

        cout << "Enter the amount to be withdrawn: ";
        cin >> Amount;

        if(Amount > balance-1000)
        {
            cout << "Insufficient balance!" << endl;
        }

        else//If not....
        {
            balance -= Amount;

            cout << "Withdrawal successful!" << endl;
        }
    }

    void display_acc_balance()
    {
        cout<< "Current balance: " << balance << endl;
    }
};

int main()
{
    class bank_account Acc[100];
    long AccFind;
    int Choice;
    int NumAcc = 0;

    
    cout << "Enter 1 to add account details." << endl;
    cout << "Enter 2 to deposit." << endl;
    cout << "Enter 3 to withdraw." << endl;
    cout << "Enter 4 to display current balance." << endl;
    cout << "Else to Exit." << endl;

    while(true)
    {
        cout << "Enter the option which you want: ";
        cin >> Choice;

        bool Found = false;

        switch (Choice)
        {
        case 1:
        {
            Acc[NumAcc].add_acc_details();
            NumAcc++;

            break;
        }

        case 2:
        {
            cout << "Enter the account number: ";
            cin >> AccFind;

            for (int i = 0; i < NumAcc; i++)
            {
                if (Acc[i].get_acc_num() == AccFind)
                {
                    Acc[i].deposit_money();

                    Found = true;

                    break;
                }
            }

            if(! Found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        case 3:
        {
            cout << "Enter the account number: ";
            cin >> AccFind;

            for (int i = 0; i < NumAcc; i++)
            {
                if (Acc[i].get_acc_num() == AccFind)
                {
                    Acc[i].withdraw_money();

                    Found = true;
                    break;
                }
            }

            if(! Found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        case 4:
        {
            cout << "Enter the account number: ";
            cin >> AccFind;
            for (int i = 0; i < NumAcc; i++)
            {
                if (Acc[i].get_acc_num() == AccFind)
                {
                    Acc[i].display_acc_balance();

                    Found = true;

                    break;
                }
            }

            if(! Found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        }

        default:
        {
            cout << "24CE082_Jenil Patel." << endl;

            return 0;
        }
        }
    }
}