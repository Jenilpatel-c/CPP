#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> student_scores;
    int num_students;
    string student_name;
    int student_score;

    cout << "enter number of students: ";
    cin >> num_students;

    for (int i = 0; i < num_students; ++i) {
        cout << "enter name of student " << i + 1 << ": ";
        cin >> student_name;
        cout << "enter score of student " << i + 1 << ": ";
        cin >> student_score;
        student_scores.push_back(make_pair(student_name, student_score));
    }

    sort(student_scores.begin(), student_scores.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    cout << "\nsorted students by scores (descending):\n";
    for (const auto& student : student_scores) {
        cout << student.first << ": " << student.second << endl;
    }

    cout << "24CE082 Jenil Patel";
    return 0;
}