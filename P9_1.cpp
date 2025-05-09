#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

double read_positive_double(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "invalid input. please enter a numeric value.\n";
        } else if (value < 0) {
            cout << "please enter a positive number.\n";
        } else {
            break;
        }
    }
    return value;
}

int main() {
    cout << "--- loan to income ratio calculator ---\n";

    double loan_amount = read_positive_double("enter total loan amount: ");
    double income = 0;

    while (true) {
        income = read_positive_double("enter your annual income: ");
        if (income == 0) {
            cout << "income cannot be zero. please enter a non-zero income.\n";
        } else {
            break;
        }
    }

    double ratio = loan_amount / income;

    cout << fixed << setprecision(2);
    cout << "\nloan-to-income ratio: " << ratio << endl;

    if (ratio > 3.5)
        cout << "warning: high loan-to-income ratio.\n";
    else if (ratio > 2.5)
        cout << "moderate risk.\n";
    else
        cout << "low risk.\n";

    cout << "24CE082 Jenil Patel";
    return 0;
}