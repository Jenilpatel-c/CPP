#include<iostream>
using namespace std;

class shape
{
    float radius;
public:
    void input_radius()
    {
        cout << "Enter radius: ";
        cin >> radius;
    }
    int get_radius()
    {
        return radius;
    }
};
class circle : private shape
{
    float area;
public:
    void calculate_area()
    {
        input_radius();
        area = 3.14 * get_radius() * get_radius();
    }
    void display_area()
    {
        cout << "Area of circle: " << area << endl;
    }
};

int main()
{
    class circle c;
    c.calculate_area();
    c.display_area();
    cout << "24CE082 Jenil Patel." << endl;
    return 0;
}