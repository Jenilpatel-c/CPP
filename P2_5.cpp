#include<iostream>
#include<math.h>
using namespace std;

class loan_acc {
    int loan_id;
    long loan_amount;
    char app_name[20];
    float interest_rate, loan_tenure;
    float emi;

    inline void calculate_emi() {
        interest_rate = interest_rate / 12 / 100;
        emi = (loan_amount * interest_rate * pow((1 + interest_rate), loan_tenure)) / (pow((1 + interest_rate), loan_tenure) - 1);
    }

public:
    void add_acc_data() {
        cout << "Enter loan ID: ";
        cin >> loan_id;
        cout << "Enter applicant's name: ";
        cin >> app_name;
        cout << "Enter total loan amount: ";
        cin >> loan_amount;
        cout << "Enter annual interest rate: ";
        cin >> interest_rate;
        cout << "Enter loan tenure in months: ";
        cin >> loan_tenure;
        calculate_emi();
    }

    void display_acc_data() {
        interest_rate = interest_rate * 12 * 100;
        cout << "Account's details:" << endl;
        cout << "Applicant's name: " << app_name << endl;
        cout << "Total loan amount: " << loan_amount << endl;
        cout << "Annual interest rate: " << interest_rate << "%" << endl;
        cout << "Loan tenure in months: " << loan_tenure << endl;
        cout << "Total EMI of loan amount: " << emi << endl;
    }

    inline int get_acc_num() {
        return loan_id;
    }
};

int main() {
    class loan_acc l[100];
    int num_acc = 0;
    int acc_find, choice;

    cout << "Enter 1 to add loan account." << endl;
    cout << "Enter 2 to display account data." << endl;
    cout << "Else to Exit." << endl;
    cout << "================================" << endl;

    while (true) {
        cout << "Enter the option which you want: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            l[num_acc].add_acc_data();
            num_acc++;
            break;
        }

        case 2: {
            cout << "Enter Loan ID: ";
            cin >> acc_find;

            bool found = false;

            for (int i = 0; i < num_acc; i++) {
                if (l[i].get_acc_num() == acc_find) {
                    l[i].display_acc_data();
                    found = true;
                    break;                          
                }
            }

            if (!found) {
                cout << "Account not found!" << endl;
            }

            break;
        }

        default: {
            cout << "24CE082_Jenil Patel";
            return 0;
        }
        }
    }
}