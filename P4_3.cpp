#include<iostream>
#include<cstring>
using namespace std;

enum fuel_type {diesel = 'D', petrol = 'P', hybrid = 'H', cng = 'C'};

class fuel
{
    fuel_type f_type;
public:
    fuel()
    {
        f_type = petrol;
    }
    void add_fuel_type()
    {
        char f_choice;
        cout << "Enter fuel type(D for diesel, P for petrol, C for CNG & H for hybrid or petrol/CNG both): ";
        while (true)
        {
            cin >> f_choice;
            switch (f_choice)
            {
            case 'D':
                f_type = diesel;
                break;
            case 'P':
                f_type = petrol;
                break;
            case 'H':
                f_type = hybrid;
                break;
            case 'C':
                f_type = cng;
                break;
            default:
                cout << "Invalid input! Please enter a valid fuel type (D, P, H, C): ";
                continue;
            }
            break;
        }
    }
    void display_fuel_type() const
    {
        switch (f_type)
        {
        case diesel:
            cout << "Fuel type: Diesel" << endl;
            break;
        case petrol:
            cout << "Fuel type: Petrol" << endl;
            break;
        case cng:
            cout << "Fuel type: CNG" << endl;
            break;
        case hybrid:
            cout << "Fuel type: Hybrid" << endl;
            break;
        }
    }
};
class brand
{
    char brand_name[10];
public:
    brand()
    {
        strcpy(brand_name, " ");
    }
    void add_brand_details()
    {
        cout << "Enter brand's name: ";
        cin >> brand_name;
    }
    void display_brand_details()
    {
        cout << "Brand's name: " << brand_name << endl;
    }
};
class car : private fuel, brand
{
    char car_name[10];
public:
    car() : fuel(), brand()
    {
        strcpy(car_name, "");
    }
    void add_car_details()
    {
        cout << "Enter car name: ";
        cin >> car_name;
        add_brand_details();
        add_fuel_type();
    }
    void display_car_details()
    {
        cout << "Entered car details:~" << endl;
        cout << "Car name: " << car_name << endl;
        display_brand_details();
        display_fuel_type();
    }
};

int main()
{
    class car c;
    c.add_car_details();
    c.display_car_details();
    cout << "24CE082 Jenil Patel" << endl;
    return 0;
}