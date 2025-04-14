#include<iostream>
using namespace std;

class employee {
    char employee_name[10];
    int basic_salary, bonus_amount, total_salary;
    inline void add_default_bonus() {
        bonus_amount = basic_salary * 0.1;
        total_salary = basic_salary + bonus_amount;
    }
    inline void add_additional_bonus() {
        cout << "Enter additional bonus: ";
        cin >> bonus_amount;
        total_salary = basic_salary + (basic_salary * 0.1) + bonus_amount;
    }
public:
    void add_employee_data() {
        int choice1;
        cout << "Enter employee's name: ";
        cin >> employee_name;
        cout << "Enter employee's basic salary: ";
        cin >> basic_salary;
        cout << "Enter 0 to add default bonus or 1 to add additional bonus: ";
        cin >> choice1;
        if (choice1 == 0) {
            add_default_bonus();
        } else if (choice1 == 1) {
            add_additional_bonus();
        } else {
            cout << "Invalid input!" << endl;
        }
        cout << "Employee's data is successfully added!" << endl;
    }
    void display_employee_data() {
        cout << "Employee details:" << endl;
        cout << "Name: " << employee_name << endl;
        cout << "Basic salary: " << basic_salary << endl;
        cout << "Bonus amount: " << bonus_amount << endl;
        cout << "Total salary: " << total_salary << endl;
    }
};
int main() {
    class employee e[100];
    int num_employee = 0;
    int choice;
    int employee_find;
    cout << "Enter 1 to add employee's data." << endl;
    cout << "Enter 2 to display employee's data." << endl;
    cout << "Else to exit." << endl;
next:
    cout << "Enter your choice which you want: ";
    cin >> choice;
    switch (choice) {
    case 1: {
        e[num_employee].add_employee_data();
        num_employee++;
        break;
    }
    case 2: {
        cout << "Enter employee's ID: ";
        cin >> employee_find;
        if (employee_find <= num_employee) {
            e[employee_find - 1].display_employee_data();
            break;
        } else {
            cout << "Employee not found!" << endl;
            break;
        }
    }
    default: {
        cout << "24CE082 Jenil Patel" << endl;
        return 0;
    }
    }
    goto next;
}