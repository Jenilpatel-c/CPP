#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class student {
    int rollnum;
    char name[10];
    float marks1, marks2, marks3, average;

    inline void calculate_average() {
        average = (marks1 + marks2 + marks3) / 3.0;
    }

public:
    student() {
        rollnum = 0;
        strcpy(name, "N/A");
        marks1 = 0;
        marks2 = 0;
        marks3 = 0;
        average = 0;
    }

    student(int s_rollno, char s_name[], int s_marks1, int s_marks2, int s_marks3) {
        rollnum = s_rollno;
        strcpy(name, s_name);
        marks1 = s_marks1;
        marks2 = s_marks2;
        marks3 = s_marks3;
    }

    void add_student_details() {
        cout << "Enter roll number: ";
        cin >> rollnum;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks of subject 1: ";
        cin >> marks1;
        cout << "Enter marks of subject 2: ";
        cin >> marks2;
        cout << "Enter marks of subject 3: ";
        cin >> marks3;
        calculate_average();
        cout << "student's details are successfully added!" << endl;
    }

    void display_student_details() {
        cout << "student's details:" << endl;
        cout << "Roll number: " << rollnum << endl;
        cout << "name: " << name << endl;
        cout << "Marks of subject 1: " << marks1 << endl;
        cout << "Marks of subject 2: " << marks2 << endl;
        cout << "Marks of subject 3: " << marks3 << endl;
        cout << "average: " << setprecision(2) << average << endl;
    }

    inline int get_rollno() {
        return rollnum;
    }
};

int main() {
    class student S[100];
    int num_stu = 0;
    int choice, stu_find;

    cout << "Enter 1 to add student's details." << endl;
    cout << "Enter 2 to display student's details." << endl;
    cout << "Else to exit." << endl;
    cout << "=====================================" << endl;

next:
    cout << "Enter your choice which you want: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        S[num_stu].add_student_details();
        num_stu++;
        break;
    }

    case 2: {
        cout << "Enter student's roll no.: ";
        cin >> stu_find;

        bool found = false;

        for (int i = 0; i < num_stu; i++) {
            if (S[i].get_rollno() == stu_find) {
                S[i].display_student_details();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "student not found!" << endl;
        }

        break;
    }

    default: {
        cout << "24CE082_Jenil Patel." << endl;
        return 0;
    }
    }
    goto next;
}