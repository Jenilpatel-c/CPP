#include <iostream>
#include <stack>
using namespace std;

class point
{
public:
    int x_coord, y_coord;

    point(int x = 0, int y = 0) : x_coord(x), y_coord(y) {}

    point operator-() const {
        return point(-x_coord, -y_coord);
    }

    point operator+(const point& other) const {
        return point(x_coord + other.x_coord, y_coord + other.y_coord);
    }

    bool operator==(const point& other) const {
        return x_coord == other.x_coord && y_coord == other.y_coord;
    }

    void display() const {
        cout << "(" << x_coord << ", " << y_coord << ")" << endl;
    }
};

class point_stack {
private:
    stack<point> point_history;

public:
    void push(const point& p) {
        point_history.push(p);
    }

    point pop() {
        if (!point_history.empty()) {
            point top_point = point_history.top();
            point_history.pop();
            return top_point;
        } else {
            return point();
        }
    }

    bool is_empty() const {
        return point_history.empty();
    }
};

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter x and y coordinates for the first input: ";
    cin >> x1 >> y1;
    cout << endl << "Enter x and y coordinates for the second input: ";
    cin >> x2 >> y2;

    point p1(x1, y1), p2(x2, y2);

    point result;

    point_stack history;

    result = p1 + p2;
    history.push(result);
    cout << "After addition: ";
    result.display();

    result = -result;
    history.push(result);
    cout << "After negation: ";
    result.display();

    cout << "Undo last operation: ";
    history.pop();
    result = history.pop();
    result.display();
    cout << "24CE082 Jenil Patel";

    return 0;
}