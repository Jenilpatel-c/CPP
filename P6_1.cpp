#include <iostream>
using namespace std;

class dynamic_array {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        int new_capacity = capacity * 2;
        int* new_data = new int[new_capacity];

        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;

        data = new_data;
        capacity = new_capacity;
    }

public:
    dynamic_array(int initial_capacity = 2) {
        capacity = initial_capacity;
        size = 0;
        data = new int[capacity];
    }

    ~dynamic_array() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "invalid index for removal." << endl;
            return;
        }

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void display() const {
        cout << "[ ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    int get_size() const {
        return size;
    }

    int get_capacity() const {
        return capacity;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            cout << "invalid index for get." << endl;
            return -1;
        }
        return data[index];
    }
};

int main() {
    dynamic_array arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    cout << "after insertions: ";
    arr.display();

    arr.remove(1);

    cout << "after removal: ";
    arr.display();

    cout << "current size: " << arr.get_size() << endl;
    cout << "current capacity: " << arr.get_capacity() << endl;
    cout << "24CE082 Jenil Patel";

    return 0;
}