#include<iostream>
using namespace std;

class product {
    int prod_ID, quantity;
    float price;
    char prod_name[20];
public:
    void add_prod() {
        cout << "Enter product ID: ";
        cin >> prod_ID;
        cout << "Enter name of product: ";
        cin >> prod_name;
        cout << "Enter price of product: ";
        cin >> price;
        quantity = 1;
        cout << "Product is added successfully!" << endl;
    }
    inline int get_ID() {
        return prod_ID;
    }
    void update_quan() {
        cout << "Enter no. of quantity to be updated: ";
        cin >> quantity;
        cout << "quantity is updated successfully!" << endl;
    }
    inline int calculate_value() {
        return quantity * price;
    }
    void display_bill() {
        cout << prod_name << "\t";
        cout << quantity << "\t\t";
        cout << price << "\t" << calculate_value() << endl;
    }
};

int main() {
    class product P[100];
    int choice;
    int prod_find;
    int prod_count = 0;
    cout << "Enter 1 to add new product." << endl;
    cout << "Enter 2 to update quantity of product." << endl;
    cout << "Enter 3 to display bill & exit." << endl;
    while (true) {
        cout << "Enter the option which you want: ";
        cin >> choice;
        bool Found = false;
        switch (choice) {
        case 1: {
            P[prod_count].add_prod();
            prod_count++;
            break;
        }
        case 2: {
            int prod_find;
            cout << "Enter product ID: ";
            cin >> prod_find;
            for (int i = 0; i < prod_count; i++) {
                if (P[i].get_ID() == prod_find) {
                    P[i].update_quan();
                    Found = true;
                    break;
                }
            }
            if (!Found) {
                cout << "Product not found!" << endl;
            }
            break;
        }
        case 3: {
            int total_value = 0;
            cout << "----------------------------------------------" << endl;
            cout << "Name\t\tquantity\tprice\tTotal" << endl;
            cout << "----------------------------------------------" << endl;
            for (int i = 0; i < prod_count; i++) {
                P[i].display_bill();
                total_value += P[i].calculate_value();
            }
            cout << "----------------------------------------------" << endl;
            cout << "Total Bill: " << total_value << endl;
            cout << "24CE082 Jenil Patel." << endl;
            return 0;
        }
        default: {
            cout << "Invalid input!" << endl;
            break;
        }
        }
    }
}