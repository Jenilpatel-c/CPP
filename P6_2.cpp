#include <iostream>
using namespace std;

class point {
private:
    int x_coord, y_coord;

public:
    point(int x = 0, int y = 0) {
        this->x_coord = x;
        this->y_coord = y;
    }

    point* move(int& dx, int& dy) {
        x_coord += dx;
        y_coord += dy;
        return this;
    }

    void display() const {
        cout << "point (" << x_coord << " , " << y_coord << ")" << endl;
    }
};

int main() {
    int x, y;

    cout << "enter initial x and y coordinates: ";
    cin >> x >> y;

    point* p = new point(x, y);

    cout << "initial position: ";
    p->display();

    int dx1, dy1, dx2, dy2;

    cout << "enter dx1 and dy1: ";
    cin >> dx1 >> dy1;

    cout << "enter dx2 and dy2: ";
    cin >> dx2 >> dy2;

    p->move(dx1, dy1)->move(dx2, dy2);

    cout << "final position after movements: ";
    p->display();

    delete p;
    cout << "24CE082 Jenil Patel";
    return 0;
}