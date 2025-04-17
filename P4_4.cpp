// This program is prepared by 24CE082 Jenil Patel
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class bank_account {
protected:
    long acc_num;
    long balance;
public:
    bank_account() {
        acc_num = 0;
        balance = 0;
    }
    void add_acc_details() {
        cout << "Enter account number: ";
        cin >> acc_num;
        cout << "Enter balance: ";
        cin >> balance;
        cout << "Account addition successful!" << endl;
    }
    void deposit_money() {
        long amount;
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful!" << endl;
        cout << "Current balance: " << balance << endl;
    }
    void withdraw_money() {
        long amount;
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;
        if (amount >= balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
            cout << "Current balance: " << balance << endl;
        }
    }
    inline long get_acc_num() {
        return acc_num;
    }
    inline long get_balance() {
        return balance;
    }
    inline void set_balance(double blnc) {
        balance = blnc;
    }
};
class savings_account : public bank_account {
    float interest_rate;
public:
    savings_account() : bank_account() {
        interest_rate = 0;
    }
    void apply_interest() {
        double interest;
        cout << "Enter interest rate: ";
        cin >> interest_rate;
        interest = get_balance() * interest_rate / 100;
        cout << "Applied interest: " << interest << endl;
    }
    void display_s_acc_details() {
        cout << "Account number: " << get_acc_num() << endl;
        cout << "Current balance: " << get_balance() << endl;
        cout << "Interest rate: " << interest_rate << "%" << endl;
    }
};
class current_account : public bank_account {
    long overdraft_limit;
public:
    current_account() : bank_account() {
        overdraft_limit = 0;
    }
    void apply_od_limit() {
        long amount;
        cout << "Enter overdraft limit: ";
        cin >> overdraft_limit;
        cout << "Enter amount to be withdrawn: ";
        cin >> amount;
        if (amount > get_balance() + overdraft_limit) {
            cout << "Invalid overdraft limit!" << endl;
            return;
        }
        set_balance(get_balance() - amount);
        cout << "Current balance: " << get_balance() << endl;
    }
     void display_c_acc_details() {
        cout << "Account number: " << get_acc_num() << endl;
        cout << "Current balance: " << get_balance() << endl;
        cout << "Overdraft limit: " << overdraft_limit << endl;
    }
};

int main() {
    class savings_account s[100];
    class current_account c[100];
    char choice1;
    int choice2, choice3;
    int num_acc1 = 0, num_acc2 = 0;
    long acc_find;
    bool found;
    cout << "Enter S for savings account." << endl;
    cout << "Enter C for current account." << endl;
    cout << "Enter E to exit." << endl;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice1;
        switch (choice1) {
        case 'S': {
            cout << "Enter 1 to add savings account's details." << endl;
            cout << "Enter 2 to deposit money." << endl;
            cout << "Enter 3 to withdraw money." << endl;
            cout << "Enter 4 to apply interest." << endl;
            cout << "Enter 5 to display account's details." << endl;
            cout << "Enter your choice: ";
            cin >> choice2;

            found = false;
            switch (choice2) {
            case 1:
                s[num_acc1].add_acc_details();
                num_acc1++;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                cout << "Enter the account number: ";
                cin >> acc_find;
                for (int i = 0; i < num_acc1; i++) {
                    if (s[i].get_acc_num() == acc_find) {
                        if (choice2 == 2) {
                            s[i].deposit_money();
                        } else if (choice2 == 3) {
                            s[i].withdraw_money();
                        } else if (choice2 == 4) {
                            s[i].apply_interest();
                        } else if (choice2 == 5) {
                            s[i].display_s_acc_details();
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
            }
            break;
        }
        case 'C': {
            cout << "Enter 1 to add current account's details." << endl;
            cout << "Enter 2 to deposit money." << endl;
            cout << "Enter 3 to withdraw money." << endl;
            cout << "Enter 4 to display account's details." << endl;

            cout << "Enter your choice: ";
            cin >> choice3;
            found = false;
            switch (choice3) {
            case 1:
                c[num_acc2].add_acc_details();
                num_acc2++;
                break;
            case 2:
            case 3:
            case 4:
                cout << "Enter the account number: ";
                cin >> acc_find;
                for (int i = 0; i < num_acc2; i++) {
                    if (c[i].get_acc_num() == acc_find) {
                        if (choice3 == 2) {
                            c[i].deposit_money();
                        } else if (choice3 == 3) {
                            c[i].apply_od_limit();
                        } else if (choice3 == 4) {
                            c[i].display_c_acc_details();
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account not found!" << endl;
                }
                break;
            default:
                cout << "Invalid input!" << endl;
                break;
            }
            break;
        }
        case 'E': {
            cout << "24CE082 Jenil Patel." << endl;
            return 0;
        }
        default: {
            cout << "Invalid input!" << endl;
            break;
        }
        }
    }
}