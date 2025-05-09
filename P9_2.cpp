#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_TRANSACTIONS = 100;

class bank_account {
private:
    string account_holder;
    double balance;
    string transactions[MAX_TRANSACTIONS];
    int transaction_count;

    void log_transaction(const string& message) {
        if (transaction_count < MAX_TRANSACTIONS) {
            transactions[transaction_count++] = message;
        } else {
            cout << "transaction log full. unable to record more transactions.\n";
        }
    }

    void log_error(const string& function_name, const string& error_message) {
        cout << "[error] in function '" << function_name << "': " << error_message << endl;
        log_transaction("error in " + function_name + ": " + error_message);
    }

public:
    bank_account(const string& name, double initial_balance) {
        account_holder = name;
        balance = initial_balance;
        transaction_count = 0;
        log_transaction("account created for " + account_holder + " with initial balance: " + to_string(balance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            log_error("deposit", "attempt to deposit non-positive amount.");
            return;
        }
        balance += amount;
        log_transaction("deposited: $" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            log_error("withdraw", "attempt to withdraw non-positive amount.");
            return;
        }
        if (amount > balance) {
            log_error("withdraw", "attempt to withdraw $" + to_string(amount) + " with only $" + to_string(balance) + " available.");
            return;
        }
        balance -= amount;
        log_transaction("withdrawn: $" + to_string(amount));
    }

    void display_balance() const {
        cout << "account holder: " << account_holder << endl;
        cout << "current balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void show_transaction_history() const {
        cout << "\ntransaction history for " << account_holder << ":\n";
        for (int i = 0; i < transaction_count; ++i) {
            cout << i + 1 << ". " << transactions[i] << endl;
        }
        if (transaction_count == 0) {
            cout << "no transactions available.\n";
        }
    }
};

int main() {
    bank_account user("john doe", 10000.0);

    user.deposit(2500);
    user.withdraw(500);
    user.withdraw(20000);
    user.deposit(-50);
    user.withdraw(1000);

    user.display_balance();
    user.show_transaction_history();

    cout << "24CE082 Jenil Patel";
    return 0;
}