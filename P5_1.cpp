#include<iostream>
#include<vector>

using namespace std;

class calculator
{
public:
    int add_int(int a, int b)
    {
        return a + b;
    }

    double add_double(double x, double y)
    {
        return x + y;
    }

    double add_int_double(int a, double b)
    {
        return a + b;
    }
};

int main()
{
    calculator calc;

    vector<double> vec;

    vec.push_back(calc.add_int(2, 3));
    vec.push_back(calc.add_double(2.3, 3.3));
    vec.push_back(calc.add_int_double(2, 3.5));

    cout << endl << "Using STL approach (vector):";
    for (double element : vec)
    {
        cout << endl << element;
    }

    cout << endl << "Using array:";

    double result_array[3];

    result_array[0] = calc.add_int(2, 3);
    result_array[1] = calc.add_double(2.4, 3.3);
    result_array[2] = calc.add_int_double(2, 3.5);

    for (int i = 0; i < 3; i++)
    {
        cout << endl << result_array[i];
    }

    cout << endl << endl << "24CE082 Jenil Patel";

    return 0;
}