#include<iostream>
using namespace std;

class bank_account {
    char acc_holder_name[10];
    long balance;
    long acc_num;
public:
    void add_acc_details() {
        cout << "Enter the account holder's name: ";
        cin >> acc_holder_name;
        cout << "Enter the account number: ";
        cin >> acc_num;
        balance = 1000;
        cout << "account addition successful!" << endl;
    }
    int get_acc_num() {
        return acc_num;
    }
    void deposit_money() {
        long amount;
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful!" << endl;
    }
    void withdraw_money() {
        long amount;
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;
        if (amount >= balance - 1000) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
    }
    void display_acc_details() {
        cout << "account holder's name: " << acc_holder_name << endl;
        cout << "account number: " << acc_num << endl;
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    class bank_account acc[100];
    long acc_find;
    int choice;
    int num_acc = 0;
    cout << "Enter 1 to add account details." << endl;
    cout << "Enter 2 to deposit." << endl;
    cout << "Enter 3 to withdraw." << endl;
    cout << "Enter 4 to display current balance." << endl;
    cout << "Else to Exit." << endl;
    while (true) {
        cout << "Enter the option which you want: ";
        cin >> choice;
        bool found = false;
        switch (choice) {
        case 1: {
            acc[num_acc].add_acc_details();
            num_acc++;
            break;
        }
        case 2: {
            cout << "Enter the account number: ";
            cin >> acc_find;
            for (int i = 0; i < num_acc; i++) {
                if (acc[i].get_acc_num() == acc_find) {
                    acc[i].deposit_money();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "account not found!" << endl;
            }
            break;
        }
        case 3: {
            cout << "Enter the account number: ";
            cin >> acc_find;
            for (int i = 0; i < num_acc; i++) {
                if (acc[i].get_acc_num() == acc_find) {
                    acc[i].withdraw_money();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "account not found!" << endl;
            }
            break;
        }
        case 4: {
            cout << "Enter the account number: ";
            cin >> acc_find;
            for (int i = 0; i < num_acc; i++) {
                if (acc[i].get_acc_num() == acc_find) {
                    acc[i].display_acc_details();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "account not found!" << endl;
            }
            break;
        }
        default: {
            cout << "24CE082 Jenil Patel." << endl;
            return 0;
        }
        }
    }
}