#include <iostream>
using namespace std;

class complex_number
{
    int real_part;
    int imaginary_part;

public:
    void set_values(int real, int imag)
    {
        real_part = real;
        imaginary_part = imag;
    }

    void display_result()
    {
        cout << endl << "Addition: " << real_part << " + ";
        cout << imaginary_part << "i" << endl;
        cout << "24CE082 Jenil Patel";
    }

    friend complex_number operator+(complex_number c1, complex_number c2);
};

complex_number operator+(complex_number c1, complex_number c2)
{
    complex_number result;
    result.real_part = c1.real_part + c2.real_part;
    result.imaginary_part = c1.imaginary_part + c2.imaginary_part;
    return result;
}

int main()
{
    complex_number c1, c2, c3;
    int real1, imag1, real2, imag2;

    cout << "Enter two complex numbers:" << endl;
    cout << "(Real and imaginary parts)" << endl;
    cout << "(Assume the first entered value is for the real part and the second for the imaginary part):" << endl;

    cout << "Enter first complex number: ";
    cin >> real1 >> imag1;
    cout << endl << "Enter second complex number: ";
    cin >> real2 >> imag2;

    c1.set_values(real1, imag1);
    c2.set_values(real2, imag2);

    c3 = c1 + c2;

    c3.display_result();
    return 0;
}
