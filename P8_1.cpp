#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_sequence(const vector<int>& data) {
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> sequence;
    int n;

    cout << "Enter number of elements in the sequence: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        sequence.push_back(val);
    }

    cout << "\nOriginal Sequence: ";
    print_sequence(sequence);

    reverse(sequence.begin(), sequence.end());

    cout << "Reversed Sequence: ";
    print_sequence(sequence);
    cout << "24CE082 Jenil Patel";
    return 0;
}
