#include <iostream>
using namespace std;

class base {
public:
    base() {
        cout << "base constructor called\n";
    }

    virtual ~base() {
        cout << "base destructor called\n";
    }
};

class derived : public base {
private:
    int* data;

public:
    derived() {
        data = new int[5];
        cout << "derived constructor called (allocated memory)\n";
    }

    ~derived() {
        delete[] data;
        cout << "derived destructor called (freed memory)\n";
    }
};

int main() {
    base* obj = new derived();
    delete obj;
    cout << "24CE082 Jenil Patel";
    return 0;
}