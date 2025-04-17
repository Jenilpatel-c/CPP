// This program is prepared by 24CE082 Jenil Patel
#include<iostream>
#include<string>
using namespace std;

class grading_framework {
protected:
    char name[15];
    float m1, m2, m3;
public:
    virtual void get_insert() = 0;
    virtual void calculate() = 0;
    virtual void display() = 0;
};

class ug_students : public grading_framework {
public:
    void get_insert() override {
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }
    void calculate() override {
        cout << "The average of 3 subjects: " << (m1 + m2 + m3) / 3 << endl;
    }
    void display() override {
        cout<< "Student details: " << endl;
        cout << "The name of student: " << name << endl;
        cout << "The marks of 3 subjects: " << m1 << ", " << m2 << ", " << m3 << endl;
        if ((m1 + m2 + m3) / 3 >= 40) {
            cout << "The student is pass" << endl;
        } else {
            cout << "The student is fail" << endl;
        }
    }
};

class pg_students : public grading_framework {
public:
    void get_insert() override {
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }
    void calculate() override {
        cout << "The average of 3 subjects: " << (m1 + m2 + m3) / 3 << endl;
    }
    void display() override {
        cout<< "Student details: " << endl;
        cout << "The name of student: " << name << endl;
        cout << "The marks of 3 subjects: " << m1 << ", " << m2 << ", " << m3 << endl;
        if ((m1 + m2 + m3) / 3 >= 50) {
            cout << "The student is pass" << endl;
        } else {
            cout << "The student is fail" << endl;
        }
    }
};

int main() {
    ug_students u;
    pg_students p;
    grading_framework *g1, *g2;
    g1 = &u;
    g2 = &p;
    int choice;
    cout << "Enter 1 for UG student "<<endl<<"Enter 2 for PG student "<<endl;
    cout<<"Enter choice:";
    cin >> choice;
    switch (choice)
    {
        case 1:
            g1->get_insert();
            g1->calculate();
            g1->display();
            break;
        case 2:
            g2->get_insert();
            g2->calculate();
            g2->display();
            break;    
        default:
            cout << "Invalid input" << endl;
    }
    cout << "24CE082 Jenil Patel" << endl;
    return 0;
}