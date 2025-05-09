#include <iostream>
#include <vector>
using namespace std;

class shape {
public:
    virtual double area() const = 0;
};

class rectangle : public shape {
    double length, width;

public:
    rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() const override {
        return length * width;
    }
};

class circle : public shape {
    double radius;

public:
    circle(double r) {
        radius = r;
    }

    double area() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    vector<shape*> shapes;

    shapes.push_back(new rectangle(5.0, 3.0));
    shapes.push_back(new circle(2.0));
    shapes.push_back(new rectangle(2.5, 4.0));
    shapes.push_back(new circle(3.5));

    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->area() << endl;
    }

    for (shape* s : shapes) {
        delete s;
    }
    cout << "24CE082 Jenil Patel";
    return 0;
}