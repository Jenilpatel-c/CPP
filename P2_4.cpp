#include<iostream>
using namespace std;

class inventory {
    int item_id;
    char item_name[20];
    float price;
    int quantity;

public:
    void add_item_details() {
        cout << "Enter item ID: ";
        cin >> item_id;
        cout << "Enter item's name: ";
        cin >> item_name;
        cout << "Enter price of item: ";
        cin >> price;
        quantity = 1;
    }

    int get_item_id() {
        return item_id;
    }

    void increase_item_quantity() {
        int new_quantity;
        cout << "Enter quantity to be increased: ";
        cin >> new_quantity;
        quantity += new_quantity;
        cout << "Item's quantity is successfully increased!" << endl;
    }

    void decrease_item_quantity() {
        int new_quantity;
        cout << "Enter quantity to be decreased: ";
        cin >> new_quantity;
        if (quantity >= new_quantity) {
            quantity -= new_quantity;
            cout << "Item's quantity is successfully decreased!" << endl;
        } else {
            cout << "Insufficient quantity for decrement!" << endl;
        }
    }

    void display_item_details() {
        cout << "Item's details:" << endl;
        cout << "ID: " << item_id << endl;
        cout << "Name: " << item_name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main() {
    class inventory items[100];
    int num_items = 0;
    int item_find, choice;

    cout << "Enter 1 to add item." << endl;
    cout << "Enter 2 to increase quantity." << endl;
    cout << "Enter 3 to decrease quantity." << endl;
    cout << "Enter 4 to display item's details." << endl;
    cout << "Else to Exit." << endl;
    cout << "==================================" << endl;

    while (true) {
        cout << "Enter the option which you want: ";
        cin >> choice;

        bool found = false;

        switch (choice) {
        case 1: {
            items[num_items].add_item_details();
            num_items++;
            break;
        }

        case 2: {
            cout << "Enter item ID: ";
            cin >> item_find;
            for (int i = 0; i < num_items; i++) {
                if (items[i].get_item_id() == item_find) {
                    items[i].increase_item_quantity();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item not found!" << endl;
            }
            break;
        }

        case 3: {
            cout << "Enter item ID: ";
            cin >> item_find;
            for (int i = 0; i < num_items; i++) {
                if (items[i].get_item_id() == item_find) {
                    items[i].decrease_item_quantity();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item not found!" << endl;
            }
            break;
        }

        case 4: {
            cout << "Enter item ID: ";
            cin >> item_find;
            for (int i = 0; i < num_items; i++) {
                if (items[i].get_item_id() == item_find) {
                    items[i].display_item_details();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Item not found!" << endl;
            }
            break;
        }

        default: {
            cout << "24CE082_Jenil Patel." << endl;
            return 0;
        }
        }
    }
}