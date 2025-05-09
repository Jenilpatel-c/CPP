#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int max_student = 100; 

struct student {
    string name;
    int mark1;
    int mark2;
    int mark3;
    double fees;
    char grade1;
    char grade2;
    char grade3;
};

ostream& column(ostream& os) {
    return os << left << setw(15);
}

char calculate_grade(int mark) {
    if (mark >= 90) return 'A';
    else if (mark >= 80) return 'B';
    else if (mark >= 70) return 'C';
    else if (mark >= 60) return 'D';
    else return 'F';
}

void print_header(ofstream& output_file) {
    output_file << column << "Name"
                << column << "Grade1"
                << column << "Grade2"
                << column << "Grade3"
                << column << "Fees" << endl;
    output_file << string(70, '-') << endl;
}

void process_students(student students[], int num_students, const string& output_file_name) {
    ofstream output_file(output_file_name);
    if (!output_file.is_open()) {
        cerr << "Error: Unable to open output file" << endl;
        return;
    }

    output_file << fixed << setprecision(2);
    print_header(output_file);

    for (int i = 0; i < num_students; ++i) {
        output_file << column << students[i].name
                    << column << students[i].grade1
                    << column << students[i].grade2
                    << column << students[i].grade3
                    << column << students[i].fees << endl;
    }

    output_file.close();
}

int main() {
    student students[max_student];
    int num_students;

    cout << "Enter number of students: ";
    cin >> num_students;

    if (num_students > max_student) {
        cout << "Error: Maximum allowed students are " << max_student << endl;
        return 1;
    }

    for (int i = 0; i < num_students; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Mark 1: ";
        cin >> students[i].mark1;
        cout << "Mark 2: ";
        cin >> students[i].mark2;
        cout << "Mark 3: ";
        cin >> students[i].mark3;
        cout << "Fees: ";
        cin >> students[i].fees;

        // Calculate gradesgghg
        students[i].grade1 = calculate_grade(students[i].mark1);
        students[i].grade2 = calculate_grade(students[i].mark2);
        students[i].grade3 = calculate_grade(students[i].mark3);
    }

    string output_file_name;
    cout << "\nEnter output file name: ";
    cin >> output_file_name;

    process_students(students, num_students, output_file_name);

    cout << "\nData has been written to " << output_file_name << endl;
    cout << "24CE082 Jenil Patel";
    return 0;
}

