#include <iostream>
using namespace std;

int main() {
    int size1, size2;

    cout << "enter the size of first sorted array: ";
    cin >> size1;
    cout << "enter the size of second sorted array: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    cout << "enter elements of first sorted array:\n";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "enter elements of second sorted array:\n";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int merged_size = size1 + size2;
    int* merged_arr = new int[merged_size];

    int i = 0, j = 0;
    for (int k = 0; k < merged_size; k++) {
        if (i < size1 && (j >= size2 || arr1[i] <= arr2[j])) {
            merged_arr[k] = arr1[i++];
        } else {
            merged_arr[k] = arr2[j++];
        }
    }

    cout << "merged sorted array:\n";
    for (int i = 0; i < merged_size; i++) {
        cout << merged_arr[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged_arr;
    cout <<"24CE082 Jenil Patel";
    return 0;
}