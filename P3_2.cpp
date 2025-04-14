#include<iostream>
using namespace std;

int sum_recursive(int array[], int n) {
    if (n == 0) {
        return 0;
    }
    return array[n - 1] + sum_recursive(array, n - 1);
}
int sum_iterative(int array[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += array[i];
    }
    return total;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }
    int recursive_sum = sum_recursive(array, n);
    cout << "Sum using recursion: " << recursive_sum << endl;
    int iterative_sum = sum_iterative(array, n);
    cout << "Sum using iteration: " << iterative_sum << endl;
    delete[] array;
    cout << "24CE082 Jenil Patel." << endl;
    return 0;
}