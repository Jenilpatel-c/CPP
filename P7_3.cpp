#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct item {
    char name[50];
    int quantity;
    float price;
};

void add_item(const char* file_name) {
    item new_item;

    cout << "enter item name: ";
    cin.getline(new_item.name, 50);

    cout << "enter quantity: ";
    cin >> new_item.quantity;

    cout << "enter price: ";
    cin >> new_item.price;
    cin.ignore();

    ofstream out_file(file_name, ios::app);
    if (!out_file) {
        cerr << "error: could not open file for writing.\n";
        return;
    }

    out_file << new_item.name << "," << new_item.quantity << "," << new_item.price << "\n";
    out_file.close();

    cout << "item added successfully.\n";
}

void view_inventory(const char* file_name) {
    ifstream in_file(file_name);
    if (!in_file) {
        cerr << "error: could not open file for reading.\n";
        return;
    }

    cout << "\n--- inventory ---\n";
    char line[128];
    while (in_file.getline(line, 128)) {
        char* token = strtok(line, ",");
        if (!token) continue;

        cout << "name: " << token;

        token = strtok(nullptr, ",");
        if (token) cout << ", quantity: " << token;

        token = strtok(nullptr, ",");
        if (token) cout << ", price: " << token;

        cout << endl;
    }

    in_file.close();
}

void search_item(const char* file_name) {
    char search_name[50];
    cout << "enter item name to search: ";
    cin.getline(search_name, 50);

    ifstream in_file(file_name);
    if (!in_file) {
        cerr << "error: could not open file.\n";
        return;
    }

    bool found = false;
    char line[128];
    while (in_file.getline(line, 128)) {
        char temp_line[128];
        strcpy(temp_line, line);

        char* token = strtok(line, ",");
        if (token && strcmp(token, search_name) == 0) {
            cout << "item found: " << temp_line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "item not found.\n";
    }

    in_file.close();
}

int main() {
    const char* file_name = "inventory.txt";
    int choice;

    do {
        cout << "\n--- inventory management ---\n";
        cout << "1. add new item\n";
        cout << "2. view inventory\n";
        cout << "3. search item\n";
        cout << "4. exit\n";
        cout << "enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: add_item(file_name); break;
            case 2: view_inventory(file_name); break;
            case 3: search_item(file_name); break;
            case 4: cout << "exiting...\n"; break;
            default: cout << "invalid option.\n";
        }

    } while (choice != 4);
    cout << "24CE082 Jenil Patel";
    return 0;
}