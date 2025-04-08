#include<iostream>
using namespace std;

class plot {
    int length, width, area, perimeter;

public:
    void add_plot_data() {
        cout << "Enter length of plot: ";
        cin >> length;
        cout << "Enter width of plot: ";
        cin >> width;
        cout << "plot's data is successfully added!" << endl;
        area = length * width;
        perimeter = 2 * (length + width);
    }

    void update_plot_data() {
        cout << "Enter new length of plot: ";
        cin >> length;
        cout << "Enter new width of plot: ";
        cin >> width;
        cout << "plot's data is successfully updated!" << endl;
        area = length * width;
        perimeter = 2 * (length + width);
    }

    void display_all_plot_data() {
        cout << "length: " << length << endl;
        cout << "width: " << width << endl;
        cout << "area: " << area << endl;
        cout << "perimeter: " << perimeter << endl;
    }

    void display_any_plot_data() {
        cout << "plot details:" << endl;
        cout << "length: " << length << endl;
        cout << "width: " << width << endl;
        cout << "area: " << area << endl;
        cout << "perimeter: " << perimeter << endl;
    }
};

int main() {
    class plot P[100];
    int choice, plotFind;
    int numplot = 0;

    cout << "Enter 1 to add plot data." << endl;
    cout << "Enter 2 to update plot data." << endl;
    cout << "Enter 3 to display plot data." << endl;
    cout << "Else to exit." << endl;
    cout << "=============================" << endl;

next:
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        P[numplot].add_plot_data();
        numplot++;
        break;
    }

    case 2: {
        cout << "Enter plot no.: ";
        cin >> plotFind;

        if (plotFind <= numplot) {
            P[plotFind - 1].update_plot_data();
            break;
        } else {
            cout << "No plot found!" << endl;
            break;
        }
    }

    case 3: {
        int choice1;
        cout << "Enter 1 to display all plot data & enter 2 to display any one plot data which you want: ";
        cin >> choice1;

        switch (choice1) {
        case 1: {
            for (int i = 1, plotNum = 0; plotNum < numplot; i++, plotNum++) {
                cout << "plot " << i << " details:" << endl;
                P[plotNum].display_all_plot_data();
            }

            if (numplot == 0) {
                cout << "No plot available to display!" << endl;
                break;
            }
            break;
        }

        case 2: {
            cout << "Enter plot number: ";
            cin >> plotFind;

            if (plotFind <= numplot) {
                P[plotFind - 1].display_any_plot_data();
                break;
            } else {
                cout << "No plot found!" << endl;
                break;
            }
        }

        default: {
            cout << "Invalid input!" << endl;
            break;
        }
        }
        break;
    }

    default: {
        cout << "24CE082_Jenil Patel " << endl;
        return 0;
    }
    }
    goto next;
}