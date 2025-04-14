#include<iostream>
using namespace std;

class bank_account
{
    char acc_holder_name[20];
    long long balance;
    long acc_num;
public:
    void add_acc_details()
    {
        cout << "Enter the account number: ";
        cin >> acc_num;
        cout << "Enter the account holder's name: ";
        cin >> acc_holder_name;
        cout << "Enter the account balance: ";
        cin >> balance;
        cout << "Account addition successful!" << endl;
    }
    void display_acc_details()
    {
        cout << "Account's details:" << endl;
        cout << "Account no. : " << acc_num << endl;
        cout << "Account holder's name: " << acc_holder_name << endl;
        cout << "Current balance: " << balance << endl;
    }
    inline long get_acc_num()
    {
        return acc_num;
    }
    inline long long get_balance()
    {
        return balance;
    }
    inline void withdraw_money(long long amount)
    {
        balance -= amount;
    }
    inline void deposit_money(long long amount)
    {
        balance += amount;
    }
};
int find_account(long acc_num, bank_account acc[], int num_acc)
{
    for (int i = 0; i < num_acc; i++)
    {
        if (acc[i].get_acc_num() == acc_num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    bank_account acc[100];
    int num_acc = 0;
    int choice;
    long long amount;
    cout << "Enter 1 to add account details." << endl;
    cout << "Enter 2 to transfer money." << endl;
    cout << "Enter 3 to display no. of accounts." << endl;
    cout << "Else to exit." << endl;
    while (true)
    {
        cout << "Enter the option which you want: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            acc[num_acc].add_acc_details();
            num_acc++;
            break;
        }
        case 2:
        {
            long acc_find_w, acc_find_d;
            int result_d, result_w;
            cout << "Enter the account no. for withdrawal: ";
            cin >> acc_find_w;
            result_w = find_account(acc_find_w, acc, num_acc);
            if (result_w == -1)
            {
                cout << "Account not found!" << endl;
                break;
            }
            cout << "Enter the account no. for deposit: ";
            cin >> acc_find_d;
            result_d = find_account(acc_find_d, acc, num_acc);
            if (result_d == -1)
            {
                cout << "Account not found!" << endl;
                break;
            }
            cout << "Enter the amount be transferred: ";
            cin >> amount;
            if (amount > acc[result_w].get_balance())
            {
                cout << "Insufficient balance!" << endl;
                break;
            }
            acc[result_w].withdraw_money(amount);
            acc[result_d].deposit_money(amount);
            cout << "Amount is successfully transferred!" << endl;
            cout << "Transaction summary:" << endl;
            acc[result_w].display_acc_details();
            acc[result_d].display_acc_details();
            break;
        }
        case 3:
        {
            cout << "The no. of account created: " << num_acc << endl;
            break;
        }
        default:
        {
            cout << "24CE082 Jenil Patel." << endl;
            return 0;
        }
        }
    }
}