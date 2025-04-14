#include<iostream>
#include<cstring>
using namespace std;

class person
{
    char name[10];
    int age;
public:
    person()
    {
        strcpy(name, " ");
        age = 0;
    }
    void add_person_data()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void display_person_data()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class employee : private person
{
    int employee_id;
public:
    employee() : person()
    {
        employee_id = 0;
    }
    void add_employee_data()
    {
        add_person_data();
        cout << "Enter employee ID: ";
        cin >> employee_id;
    }
    void display_employee_data()
    {
        display_person_data();
        cout << "Employee ID: " << employee_id << endl;
    }
};
class manager : private employee
{
    char department[10];
public:
    manager() : employee()
    {
        strcpy(department, " ");
    }
    void add_manager_data()
    {
        add_employee_data();
        cout << "Enter department: ";
        cin >> department;
    }
    void display_manager_data()
    {
        cout << "Entered data:~" << endl;
        display_employee_data();
        cout << "Department: " << department << endl;
    }
};
int main()
{
    manager m;
    m.add_manager_data();
    m.display_manager_data();
    cout << "24CE082_Jenil Patel." << endl;
    return 0;
}